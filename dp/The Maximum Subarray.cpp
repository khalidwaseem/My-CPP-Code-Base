/* Given an array A = {a1, a2, ..., aN} of N elements, find the maximum possible sum of a
1. Contiguous subarray
2. Non-contiguous (not necessarily contiguous) subarray.
Empty subarrays/subsequences should not be considered.

Input Format
First line of the input has an integer T. T cases follow. 
Each test case begins with an integer N. In the next line, N integers follow representing the elements of array A.

Constraints:
The subarray and subsequences you consider should have at least one element.

Output Format
Two, space separated, integers denoting the maximum contiguous and non-contiguous subarray. At least one integer should be selected and put into the 
subarrays(this may be required in cases where all elements are negative).

Sample Input

2 
4 
1 2 3 4
6
2 -1 2 3 4 -5

Sample Output

10 10
10 11

Explanation

In the first case: 
The max sum for both contiguous and non-contiguous elements is the sum of ALL the elements (as they are all positive).

In the second case: 
[2 -1 2 3 4] --> This forms the contiguous sub-array with the maximum sum. 
For the max sum of a not-necessarily-contiguous group of elements, simply add all the positive elements. */

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iterator>

#define tr(c, itr) for(decltype(c.begin()) itr = c.begin(); itr != c.end(); itr++)

using namespace std;

pair<long,long> contSum(vector<int> &vec){
    pair<long,long> p;
    
    if(vec.size() == 1){
        p.first = vec[0];
        //p.second = max(0,vec[0]);
        p.second = vec[0];
        return p;
    }else{
        long curEle = vec[vec.size()-1];  
        vec.pop_back();
        p = contSum(vec);
        //long prevMax = p.first;
        pair<long,long> tempP;
        tempP.first = max(curEle,curEle + p.first);
        tempP.second = max(tempP.first,p.second);
        return tempP;
    }
}

long nonContSum(vector<int> &vec){
    if(vec.size() == 1){
        return vec[0];
    }else{
        long curEle = vec[vec.size()-1];  
        vec.pop_back();
        long prevMax = nonContSum(vec);
        return max(max(curEle,curEle+prevMax),prevMax);
    }   
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int T;
    int N;
    int data;
    vector<int> vec;
    
    cin >> T;
    
    for(int i=0; i<T; i++){
        cin >> N;
        for(int j=0; j<N; j++){
            cin >> data;
            vec.push_back(data);
        }
        /*tr(vec,it){
            cout << *it;
        }*/
        
        vector<int> vecCopy(vec);
        
        pair<long, long> pr = contSum(vec);
        cout << pr.second << " "<< nonContSum(vecCopy) << endl;
        
        vec.clear();
        vecCopy.clear();
    }
    return 0;
}

