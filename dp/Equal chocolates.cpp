/*
Christy is interning at HackerRank. One day she has to distribute some chocolates to her colleagues. 
She is biased towards her friends and may have distributed the chocolates unequally. 
One of the program managers gets to know this and orders Christy to make sure everyone gets equal number of chocolates.
But to make things difficult for the intern, she is ordered to equalize the number of chocolates for every colleague in 
the following manner,

For every operation, she can choose one of her colleagues and can do one of the three things.

1) She can give one chocolate to every colleague other than chosen one.
2) She can give two chocolates to every colleague other than chosen one.
3) She can give five chocolates to every colleague other than chosen one.

Calculate minimum number of such operations needed to ensure that every colleague has the same number of chocolates.

Input Format

First line contains an integer T denoting the number of testcases. T testcases follow. 
Each testcase has 2 lines. First line of each testcase contains an integer N denoting the number of co-interns. 
Second line contains N space separated integers denoting the current number of chocolates each colleague has.

Output Format

T lines, each containing the minimum number of operations needed to make sure all colleagues have the same number of 
chocolates.

Sample Input

1
4
2 2 3 7

Sample Output

2 
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

int findMin(vector<int> &vec){
    int min = vec[0];
    for(int i=0; i<vec.size(); i++){
        if(vec[i]<min)
            min = vec[i];
    }
    return min;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int T,N;
    cin >> T;
    for(int t=0; t<T; t++){
        cin >> N;
        vector<int> a(N);
        for(int i=0; i<N; i++){
            cin >> a[i];
        }
        //Find minimum
        int M = findMin(a);
        int start = max(0,M-4);
        vector<int> count(M-start+1,0);
        int counter = 0;
        
        for(int base=start; base<=M; base++,counter++){
            vector<int> vec = a;
            for(int i=0; i<N; i++){
                if((vec[i]-base)>=5 && (vec[i]-base)%5 >= 0){
                    count[counter] = count[counter] + (vec[i]-base)/5;
                    vec[i] = (vec[i]-base)%5 + base;
                }
                if((vec[i]-base)>=2 && (vec[i]-base)%2 >= 0){
                    count[counter] = count[counter] + (vec[i]-base)/2;
                    vec[i] = (vec[i]-base)%2 + base;
                }
                if((vec[i]-base)>=1 && (vec[i]-base)%1 >= 0){
                    count[counter] = count[counter] + (vec[i]-base)/1;
                    vec[i] = (vec[i]-base)%1 + base;
                }
            }
            vec.clear();
        }
        /*// Print output
        for(int i=0; i<count.size(); i++){
            cout << count[i] << endl;
        }*/
        cout << findMin(count) << endl;
        
        // Clear ds
        a.clear();
        count.clear();
        
    }
    return 0;
}
