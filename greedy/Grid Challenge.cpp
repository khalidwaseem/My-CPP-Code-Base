/*
Given a squared sized grid  of size N in which each cell has a lowercase letter. Denote the 
character in the i th row and in the j th column as G[i][j].

You can perform one operation as many times as you like: Swap two column adjacent characters 
in the same row  G[i][j] and  G[i][j+1] for all valid i,j.

Is it possible to rearrange the grid such that the following condition is true?

 G[i][1] <= G[i][2] <= ... G[i][N] for 1<=i<=N and 
 G[1][j] <= G[2][j] <= ... G[N][j] for 1<=j<=N

In other words, is it possible to rearrange the grid such that every row and every column is 
lexicographically sorted?

Note: c1<=c2, if letter c1 is equal to c2 or is before c2 in the alphabet.

Input Format

The first line begins with T, the number of testcases. In each testcase you will be given N. 
The following N lines contain N lowercase english alphabet each, describing the grid.

Output Format

Print T lines. On the th line print YES if it is possible to rearrange the grid in the ith 
testcase or NO otherwise.

Sample Input

1
5
ebacd
fghij
olmkn
trpqs
xywuv

Sample Output

YES
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int T;
    cin >> T;
    for(int t=0; t<T; t++){
        int N;
        cin >> N;
        vector<vector<char> > matrix(N,vector<char>(N));
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                cin >> matrix[i][j];
            }
        }
        
        int flag = 1;
        sort(matrix[0].begin(),matrix[0].end());
        for(int i=1; i<N; i++){
            sort(matrix[i].begin(),matrix[i].end());
            flag = 1;
            for(int j=0; j<N; j++){
                if(matrix[i][j]<matrix[i-1][j]){
                    flag = 0;
                    break;
                }
            }
            if(flag == 0){
                break;
            }
        }
        
        if(flag)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
        
        matrix.clear();
        
        /*//Print
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                cout << matrix[i][j];
            }
            cout << endl;
        }*/
    }
    return 0;
}

