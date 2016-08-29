/*
Samantha and Sam are playing a game. They have 'N' balls in front of them, each ball numbered from 0 to 9, except the first ball which is numbered from 1 to 9. 
Samantha calculates all the sub-strings of the number thus formed, one by one. If the sub-string is S, Sam has to throw 'S' candies into an initially empty box. 
At the end of the game, Sam has to find out the total number of candies in the box, T. As T can be large, Samantha asks Sam to tell T % (10^9+7) instead. 
If Sam answers correctly, he can keep all the candies. Sam can't take all this Maths and asks for your help.

Help him!

Input Format 
A single line containing a string of numbers that appear on the first, second, third ball and so on.

Output Format 
A single line which is the number of candies in the box, T % (10^9+7)

Constraints 
1 ≤ N ≤ 2*10^5

Sample Input #01

123

Sample Output #01

164

Explanation #01

The sub-strings of 123 are 1, 2, 3, 12, 23, 123 which sums to 164.
*/

// Method 1: Without DP
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;
#define ull long long int

ull MOD = pow(10,9)+7;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    string str;    
    cin >> str;
    ull N = str.size();
    //cout << N << endl;
    ull result = 0;
    ull f = 1;
    for(ull i=N-1; i>=0; i--){
        //cout << i << endl;
        result = result + ((str[i]-'0')*(i+1)*f) % MOD;
        f = (f*10+1) % MOD;
        cout << f << endl;
    }
    
    cout << result % MOD << endl;
    
    return 0;
}

// Method 2: Using DP
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;
#define ull long long int

ull MOD = pow(10,9)+7;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    string str;    
    cin >> str;
    ull N = str.size();
    
    
    vector<ull> s(N,0);
    s[0] = str[0] - '0';
    
    ull result = s[0];
    for(ull i=1; i<N; i++){
        
        s[i] = ((i+1)*(str[i]-'0') + 10*s[i-1]) % MOD;
        result = result + s[i];

    }
    
    cout << result % MOD << endl;
    
    return 0;
}

