/*
You are given two arrays, A and B, both containing N integers.

A pair of indices (i,j) is beautiful if the ith element of array A is equal to 
the jth element of array B. In other words, pair (i,j) is beautiful if and only 
if Ai=Bj.

Given A and B, there are k pairs of beautiful indices (i0,j0),...,(ik-1,jk-1). 
A pair of indices in this set is pairwise disjoint if and only if for 
each 0<=x<y<=k-1 it holds that ix!=iy and jx!=jy.

Change exactly 1 element in B so that the resulting number of pairwise 
disjoint beautiful pairs is maximal, and print this maximal number to stdout.

Input Format

The first line contains a single integer, N (the number of elements in A and B). 
The second line contains N space-separated integers describing array A. 
The third line contains N space-separated integers describing array B.

Output Format

Determine and print the maximum possible number of pairwise disjoint beautiful pairs.

Note: You must first change 1 element in B, and your choice of element must be optimal.

Sample Input

3
1 2 2
1 2 3

Sample Output

3
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iterator>

using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int N;
    cin >> N;
    vector<int> A(N);
    vector<int> B(N);
    
    for(int i=0; i<N; i++){
        cin >> A[i];
    }
    for(int i=0; i<N; i++){
        cin >> B[i];
    }
    
    int K = 0;
    vector<int>::iterator itr;
    sort(B.begin(),B.end());
    
    for(int i=0; i<N; i++){
        itr = lower_bound(B.begin(),B.end(),A[i]);
        if(itr!=B.end()&&*itr==A[i]){
            K++;
            B.erase(itr);
        }
    }
    if(K==N){
        K = K-1;
    }else{
        K = K+1;
    }
    cout << K << endl;
    return 0;
}
