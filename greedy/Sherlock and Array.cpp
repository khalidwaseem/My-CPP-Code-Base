/*
Watson gives Sherlock an array A of length N. Then he asks him to determine if there exists an element 
in the array such that the sum of the elements on its left is equal to the sum of the elements on its 
right. If there are no elements to the left/right, then the sum is considered to be zero. 
Formally, find an i, such that, A1 + A2 ... Ai-1 = Ai+1 + Ai+2 ... AN.

Input Format 
The first line contains T, the number of test cases. For each test case, the first line contains N, 
the number of elements in the array A. The second line for each test case contains N space-separated 
integers, denoting the array A.

Output Format 
For each test case print YES if there exists an element in the array, such that the sum of the elements 
on its left is equal to the sum of the elements on its right; otherwise print NO.

Sample Input

2
3
1 2 3
4
1 2 3 3

Sample Output

NO
YES
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int T;
    cin >> T;
    for(int t=0; t<T; t++){
        int N;
        cin >> N;
        vector<int> vec(N);
        for(int i=0; i<N; i++){
            cin >> vec[i];
        }
        
        if(N==1){
            cout << "YES" << endl;
            continue;
        }
        
        vector<int> vec1(N);
        vector<int> vec2(N);
        vec1[0] = vec[0];
        vec2[N-1] = vec[N-1];
        
        // Cumulative sum
        for(int i=0; i<N-1; i++){
            vec1[i+1] = vec[i+1]+vec1[i];
        }
        for(int i=N-1; i>0; i--){
            vec2[i-1] = vec[i-1]+vec2[i];
        }
        
        int flag = 0;
        for(int i=1; i<N-1; i++){
            if(vec1[i-1] == vec2[i+1]){
                cout << "YES" << endl;
                flag = 1;
                break;
                
            }
        }
        
        if(flag == 0){
            cout <<"NO" << endl;
        }
        
    }
    return 0;
}


