/*
A rabbit is sitting at x = 0. It can only jump to the right towards the positive x-axis. 
In the kth jump, the rabbit jumps either k meters or k+1 meters to the right. For example, 
in the 5th jump the rabbit can jump either 5 meters or 6 meters to the right. What is the 
minimum number of jumps needed for the rabbit to reach point p?

Input Format

The first line contains an integer T, the number of test cases. This is followed by T test 
cases: Each test case contains one positive integer p, the point where the rabbit needs to reach.

Output Format

For each testcase, print in a new line the minimum number of jumps needed for the rabbit 
to reach point p.

Sample Input

2
1
7

Sample Output

1
3
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
    int T;
    cin >> T;
    vector<lli> vec;
    lli p = 0;
    lli k = 2;
    while(p<=pow(10,8)){
        vec.push_back(p);
        p = p + k;
        k++;
    }
    
    vector<lli>::iterator itr;
    
    for(int t=0; t<T; t++){
        lli P;
        cin >> P;
        itr = lower_bound(vec.begin(),vec.end(),P);
        
        cout << itr-vec.begin() << endl;
        
    }
    return 0;
}