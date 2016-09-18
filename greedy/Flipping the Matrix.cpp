/*
Sean invented a game involving a 2n*2n matrix where each cell of the matrix contains an integer. 
He can reverse any of its rows or columns any number of times, and the goal of the game is to 
maximize the sum of the elements in the n*n submatrix located in the upper-left corner of 
the 2n*2n matrix (i.e., its upper-left quadrant).

Given the initial configurations for  matrices, help Sean reverse the rows and columns of each 
matrix in the best possible way so that the sum of the elements in the matrix's upper-left 
quadrant is maximal. For each matrix, print the maximized sum on a new line.

Input Format

The first line contains an integer, q, denoting the number of queries. The subsequent lines 
describe each of the q queries in the following format:

1) The first line of each query contains an integer, n.
2) Each line i of the 2n subsequent lines contains 2n space-separated integers describing 
the respective values of row i in the matrix.

Output Format

You must print q lines of output. For each query (i.e., matrix), print the maximum possible 
sum of the elements in the matrix's upper-left quadrant.

Sample Input

1
2
112 42 83 119
56 125 56 49
15 78 101 43
62 98 114 108

Sample Output

414
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int Q;
    cin >> Q;
    for(int q=0; q<Q; q++){
        int N;
        cin >> N;
        int M = 2*N;
        vector<vector<int> > mat(M,vector<int>(M));
        
        for(int i=0; i<M; i++){
            for(int j=0; j<M; j++){
                cin >> mat[i][j];
            }           
        }
        
        long long int sum = 0;
        vector<int> elements;
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                elements.push_back(mat[i][j]);
                elements.push_back(mat[i][M-j-1]);
                elements.push_back(mat[M-i-1][j]);
                elements.push_back(mat[M-i-1][M-j-1]);
                sum += *max_element(elements.begin(),elements.end());
                elements.clear();
            }
        }
        cout << sum << endl;
        mat.clear();
    }
    return 0;
}


