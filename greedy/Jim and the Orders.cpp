/*
Jim's Burgers has n hungry burger fans waiting in line. Each unique order, i, is placed 
by a customer at time ti, and the order takes di units of time to process.

Given the information for all n orders, can you find and print the order in which all n 
customers will receive their burgers? If two or more orders are fulfilled at the exact 
same time t, sort them by ascending order number.

Input Format

The first line contains a single integer, n, denoting the number of orders. 
Each of the n subsequent lines contains two space-separated integers describing the 
respective values of ti and di for order i.

Output Format

Print a single line of n space-separated order numbers (recall that orders are 
numbered from 1 to n) describing the sequence in which the customers receive their burgers. 
If two or more customers receive their burgers at the same time, print the smallest order 
number first.

Sample Input 1

5
8 1
4 2
5 6
3 1
4 3

Sample Output 1

4 2 5 1 3
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
    int N;
    cin >> N;
    vector<pair<lli, int> > vec;
    lli t,d;
    for(int i=1; i<=N; i++){
        cin >> t >> d;
        vec.push_back(pair<lli,int>(t+d,i));
    }
    
    sort(vec.begin(),vec.end());
    
    //Print
    for(int i=0; i<N; i++){
        cout << vec[i].second << " " ;
    }
    return 0;
}
