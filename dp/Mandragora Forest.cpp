/*
The evil forest is guarded by N vicious mandragoras. Each ith mandragora has Hi health points (1<=i<=N).

Garnet and her pet begin their journey through the evil forest with S=1 strength points and P=0 experience points. For each undefeated mandragora i, she can perform either of the following actions:

1. Garnet's pet eats mandragora i. This increments S by 1 and defeats mandragora i.
2. Garnet's pet battles mandragora i. This increases P by S*Hi experience points and defeats mandragora i.

Each mandragora can only be defeated once, and Garnet can defeat the mandragoras in any order. Given the respective health points for each mandragora, can you find the maximum number of experience points she can earn from defeating all N mandragoras?

Input Format

The first line contains an integer, T, denoting the number of test cases. Each test case is described over two lines:

1. The first line contains a single integer, N, denoting the number of mandragoras in the forest.
2. The second line contains N space-separated integers describing the respective health points for the mandragoras (i.e., H1,H2,H3,...,Hn).

Output Format

For each test case, print a single line with an integer denoting the maximum number of experience points that Garnet can earn.

Sample Input

1
3
3 2 2

Sample Output

10 
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

long long calulateSum(vector<long long> &H){
    long long sum = 0;
    for(long long i=0;i<H.size();i++){
        sum = sum + H[i];
    }
    return sum;
}

long long findMax(vector<long long> &P){
    long long max = P[1];
    for(long long i=0;i<P.size();i++){
        if(P[i]>max)
            max = P[i];
    }
    return max;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    long long T,N;
    cin >> T;
    
    for(long long i=0;i<T;i++){
        cin >> N;
        vector<long long> H(N);
        for(long long j=0;j<N;j++){
            cin >> H[j];
        }
        
        sort(H.begin(),H.end());
        //cout << calulateSum(H);
        vector<long long> P(N,0);
        
        P[0] = calulateSum(H);
        for(long long i=1;i<N;i++){
            P[i] = (i+1)*((P[i-1]/i)-H[i-1]);            
        }
        
        cout << findMax(P) << endl;
    }
    return 0;
}


