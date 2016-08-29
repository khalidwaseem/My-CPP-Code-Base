/*
Array A contains the elements, A1, A2, ... AN. And array B contains the elements, B1, B2, ... BN. There is a relationship 
between Ai and Bi, ∀ 1 ≤ i ≤ N, i.e., any element Ai lies between 1 and Bi.

Let cost S of an array A is defined as:

S = Summation(i=2 to N)|Ai - Ai-1|

You have to print the largest possible value of S.

Input Format 
The first line contains, T, the number of test cases. Each test case contains an integer, N, in first line. 
The second line of each test case contains N integers that denote the array B.

Output Format 
For each test case, print the required answer in one line.

Sample Input

1
5
10 1 10 1 10

Sample Output

36

Explanation 
The maximum value occurs when A1=A3=A5=10 and A2=A4=1.
*/

#include <cstdio>
#include <cmath>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define ll long long int

int main(){
    int T;
    cin >> T;
    for(int t=0; t<T; t++){
        int N;
        cin >> N;
        vector<int> b(N);
        // Input
        for(int i=0; i<N; i++){
            cin >> b[i];
        }
        
        vector<vector<ll> > dp(N,vector<ll>(2,0));
        
        for(int i=1; i<N; i++){
            dp[i][0] = max(dp[i-1][0] , dp[i-1][1]+abs(1-b[i-1]));
            dp[i][1] = max(dp[i-1][0]+abs(b[i]-1) , dp[i-1][1]+abs(b[i]-b[i-1]));
        }
        cout << max(dp[N-1][0],dp[N-1][1]) << endl;
        b.clear();
        dp.clear();
    }
    return 0;
}