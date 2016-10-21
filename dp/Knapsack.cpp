/*
Given a list of n integers, A={a1,a2,...,an}, and another integer, k representing the expected sum. Select zero or more numbers from A such that the sum of these numbers is as near as possible, but not exceeding, to the expected sum (k).

Note

- Each element of A can be selected multiple times.
- If no element is selected then the sum is 0.

Input Format

The first line contains T the number of test cases. 
Each test case comprises of two lines. First line contains two integers, n, k, representing the length of list A and expected sum, respectively. Second line consists of n space separated integers, a1,a2,a3,...,an, representing the elements of list A.

Output Format

Output T lines, the maximum sum for each test case which is as near as possible, but not exceeding, to the expected sum (k).

Sample Input

2
3 12
1 6 9
5 9
3 4 4 4 8

Sample Output

12
9

*/

#include<cstdio>
#include<cmath>
#include<iostream>
#include<vector>
#include<algorithm>
#include<set>

using namespace std;

int knapsack(set<int> array, int k){
    if(array.size()==0 || k==0){
        return k;     
    }else if(k < *(array.begin())){
        return k;
    }else{
        int data = *(array.begin());
        int v1,v2;
        if(k-data >=0)
            v1 = knapsack(array, k-data);
        else
            v1 = k;
        array.erase(array.begin());
        v2 = knapsack(array, k);
        return min(v1,v2);                
    }
    return 0;            
}

int main(){
    int T,N,K;
    cin >> T;
    
    for(int t=0; t<T; t++){
        // Input
        cin >> N >> K;
        set<int> array;
        int data;
        for(int i=0; i<N; i++){
            cin >> data;
            array.insert(data);
        }
        
        int val = knapsack(array,K);
        cout <<K-val<<endl;
    }
    return 0;
}