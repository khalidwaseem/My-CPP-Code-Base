/*
A subsequence is a sequence that can be derived from another sequence by deleting some elements without changing the order of the remaining elements. 
Longest common subsequence (LCS) of 2 sequences is a subsequence, with maximal length, which is common to both the sequences. 
Given two sequence of integers,  A = {a1, a2, a3, ... , an} and  B = {b1, b2, b3, ... , bm} find any one longest common subsequence.
In case multiple solutions exist, print any of them. It is guaranteed that at least one non-empty common subsequence will exist.

Input Format

First line contains two space separated integers, n and m, where n is the size of sequence A, while m is size of sequence B. 
In next line there are n space separated integers representing sequence A, and in third line there are m space separated 
integers representing sequence B.

n m
A1 A2 … An 
B1 B2 … Bm

Output Format

Print the longest common subsequence and each element should be separated by at least one white-space. In case of multiple answers, 
print any one of them.

Sample Input

5 6
1 2 3 4 1
3 4 1 2 1 3

Sample Output

1 2 3
*/

#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n,m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    
    // Input
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    for(int i=0; i<m; i++){
        cin >> b[i];
    }
    
    // Calculate |LCS(a,b)|
    vector< vector<int> > lcs(n+1, vector<int>(m+1)); 
    for(int i=0; i<n+1; i++){
        for(int j=0; j<m+1; j++){
            if(i==0||j==0){
                lcs[i][j] = 0;
            }else if(a[i-1] == b[j-1]){
                lcs[i][j] = lcs[i-1][j-1] + 1;
            }else{
                lcs[i][j] = max(lcs[i-1][j],lcs[i][j-1]);
            }                
        }
    }
    
    // Print Table
    /*for(int i=0; i<n+1; i++){
        for(int j=0; j<m+1; j++){
            cout << lcs[i][j] <<" ";
        }
        cout <<endl;
    }*/
    
    // Find any one LCS
    vector<int> seq;
    int i = n, j=m;
    while(i>0 && j>0){
        if(a[i-1] == b[j-1]){
            seq.push_back(a[i-1]);
            i--;j--;         
        }else{
            if(lcs[i-1][j] >= lcs[i][j-1]){
                i--;
            }else{
                j--;
            }
        }
    }

    // Print any one LCS    
    for(int i=seq.size()-1; i>=0; i--){
        cout << seq[i] << " ";
    }
    
    return 0;
}
  