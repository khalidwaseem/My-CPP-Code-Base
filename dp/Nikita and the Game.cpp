/* 
Nikita just came up with a new array game. The rules are as follows:

Initially, there is an array A, containing N integers. In each move, Nikita must partition the array into 2 non-empty 
parts such that the sum of the elements in the left partition is equal to the sum of the elements in the right 
partition. If Nikita can make such a move, she gets point; otherwise, the game ends.
After each successful move, Nikita discards either the left partition or the right partition and continues playing 
by using the remaining partition as array. Nikita loves this game and wants your help getting the best score possible. 
Given A, can you find and print the maximum number of points she can score?

Input Format

The first line contains an integer T, denoting the number of test cases. Each test case is described over 2 lines 
in the following format:

1. A line containing a single integer N, denoting the size of array A.
2. A line of N space-separated integers describing the elements in array A.

Output Format

For each test case, print Nikita's maximum possible score on a new line.

Sample Input

3
3
3 3 3
4
2 2 2 2
7
4 1 0 1 1 0 1

Sample Output

0
2
3

*/

/* O(NLogN) */

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iterator>
using namespace std;

#define lli long long int

lli optimal(vector<lli>& cumsum, lli start, lli end, lli prevMid){
    if(start == end) {
        return 0;
    } else if((cumsum[end]-prevMid)%2 != 0){
        return 0;
    } else {
        lli toSearch = prevMid + (cumsum[end]-prevMid)/2;
        vector<lli>::iterator itr;
        itr = lower_bound(cumsum.begin()+start, cumsum.begin()+end, toSearch);
        if(*itr == toSearch){
            lli left = optimal(cumsum, start, itr - cumsum.begin(), prevMid);            
            lli right =optimal(cumsum, itr-cumsum.begin()+1, end, toSearch);            
            return max(left,right) + 1;    
        }else{ // Not possible to divide in half
            return 0;
        }
    }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int T;
    cin >> T;
    lli N;    
    for(int t=0; t<T; t++){
        cin >> N;
        vector<lli> vec(N);
        for(lli i=0; i<N; i++){
            cin >> vec[i];
        }
        
        vector<lli> cumsum(N);
        cumsum[0] = vec[0];
        for(lli i=1; i<N; i++){
            cumsum[i] = cumsum[i-1] + vec[i];
        }
        
        cout << optimal(cumsum,0,N-1,0) <<endl;
        
        vec.clear();
        cumsum.clear();
        
        /*// Print Input
        for(lli i=0; i<N; i++){
            cout << cumsum[i] << endl;
        }*/
    }
    
    return 0;
}
