/*
HackerRank-city is an acyclic connected graph (or tree). Its not an ordinary place, the construction of the whole tree takes place in N steps. The process is described below:

- It initially has 1 node.
- At each step, you must create 3 duplicates of the current tree, and create 2 new nodes to connect all 4 copies in the following H shape:

At each ith step, the tree becomes 4 times bigger plus 2 new nodes, as well as 5 new edges connecting everything together. The length of the new edges being added at step i is denoted by input Ai.

Calculate the sum of distances between each pair of nodes; as these answers may run large, print your answer modulo 1000000007.

Input Format

The first line contains an integer, N (the number of steps). The second line contains N space-separated integers describing A0,A1,...,An-1.

Output Format

Print the sum of distances between each pair of nodes modulo 1000000007.

Sample Input 0

1
1
Sample Output 0

29
Sample Input 1

2
2 1
Sample Output 1

2641

*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define lli long long int
#define P 1000000007

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    
    int N;
    cin >> N;
    int a;
    lli x=0,y=1,z=0,ans=0;
    
    for(int i=0; i<N; i++){
        cin >> a;
        
        ans=ans*4+  //answer
            (y*12+8)%P*x%P+
            (y*12+8)%P*y%P*a+
            (y*2+1)%P*(y*2+1)%P*a;

        x=  x*4+    //from corner to all
            (z+a*2)%P*y%P+
            (z+a*3)%P*y%P*2+
            z*2+a*3;

        y=  y*4+2;  // number of nodes

        z=  z*2+a*3;//diameter

        ans%=P;
        x%=P;
        y%=P;
        z%=P;
        
    }
    
    /*vector<lli> dp(N+1);
    vector<lli> cornerSumDist(N+1);
    vector<lli> noNodes(N+1);
    vector<lli> diameterTree(N+1);
    
    dp[0] = 0;
    cornerSumDist[0] = 0;
    noNodes[0] = 1;
    diameterTree[0] = 0;
    
    for(int i=1; i<=N; i++){
        
        dp[i] = 4*dp[i-1] + 
            (12*noNodes[i-1]+8)%M * cornerSumDist[i-1]%M + 
            (12*noNodes[i-1]+8)%M * noNodes[i-1]%M * A[i-1] + 
            (2*noNodes[i-1]+1)%M * (2*noNodes[i-1]+1)%M * A[i-1];
        
        cornerSumDist[i] = 4*cornerSumDist[i-1] + 
            (diameterTree[i-1]+2*A[i-1])%M * noNodes[i-1]%M + 
            (diameterTree[i-1]+3*A[i-1])%M * (noNodes[i-1]%M) * 2 + 
            diameterTree[i-1] * 2 + 
            A[i-1] * 3;
        
        noNodes[i] = 4*noNodes[i-1] + 2;
        
        diameterTree[i] = 2*diameterTree[i-1] + 2*A[i-1];
        
        dp[i] = dp[i] % M;
        cornerSumDist[i] = cornerSumDist[i] % M;
        noNodes[i] = noNodes[i] % M;
        diameterTree[i] = diameterTree[i] % M;
    }*/
    
    cout<< ans << endl;
    
    return 0;
}
