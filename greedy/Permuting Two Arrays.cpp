/*
Consider two n-element arrays of integers, A = [a0,a1,...,an-1] and B = [b0,b1,...,bn-1]. 
You want to permute them into some A' and B' such that the relation ai'+bi'>=K holds for 
all i where 0<=i<n. For example, if A=[0,1], B=[0,2], and K=1, a valid A',B' satisfying 
our relation would be A'=[1,0] and B'=[0,2].

You are given q queries consisting of A, B, and K. For each query, print YES on a new 
line if some permutations A', B' exist satisfying the relation above. If no valid 
permutations exist, print NO instead.

Input Format

The first line contains an integer, q, denoting the number of queries. The 3q subsequent 
lines describe each of the queries in the following format:

1) The first line contains two space-separated integers describing the respective values 
of n (the size of arrays A and B) and K (the relation variable).
2) The second line contains n space-separated integers describing the respective elements 
of array A.
3) The third line contains n space-separated integers describing the respective elements 
of array B.

Output Format

For each query, print YES on a new line if valid permutations exist; otherwise, print NO.

Sample Input

2
3 10
2 1 3
7 8 9
4 5
1 2 2 1
3 3 3 4

Sample Output

YES
NO
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define lli long long int

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int Q;
    cin >> Q;
    for(int q=0; q<Q; q++){
        int N;
        lli K;
        cin >> N >> K;
        
        vector<lli> A(N);
        vector<lli> B(N);
        
        for(int i=0; i<N; i++){
            cin >> A[i];
        }
        for(int i=0; i<N; i++){
            cin >> B[i];
        }
        
        sort(A.begin(),A.end());
        sort(B.rbegin(),B.rend());
        
        int flag = 1;
        for(int i=0; i<N; i++){
            if(A[i]+B[i] < K){
                flag = 0;
                break;
            }
        }
        
        if(flag == 1){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
        
        A.clear();
        B.clear();
        
    }
    return 0;
}
