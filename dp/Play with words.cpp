/*
Shaka and his brother have created a boring game which is played like this:

They take a word composed of lowercase English letters and try to get the 
maximum possible score by building exactly 2 palindromic subsequences. 
The score obtained is the product of the length of these 2 subsequences.

Let's say A and B are two subsequences from the initial string. If Ai & Aj 
are the smallest and the largest positions (from the initial word) respectively 
in A; and Bi & Bj are the smallest and the largest positions (from the initial word) 
respectively in B, then the following statements hold true: 
Ai <= Aj, 
Bi <= Bj, & 
Aj < Bi. 
i.e., the positions of the subsequences should not cross over each other.

Hence the score obtained is the product of lengths of subsequences A & B. Such 
subsequences can be numerous for a larger initial word, and hence it becomes 
harder to find out the maximum possible score. Can you help Shaka and his 
brother find this out?

Input Format 
Input contains a word S composed of lowercase English letters in a single line.

Output Format 
Output the maximum score the boys can get from S.

Sample Input:

eeegeeksforskeeggeeks

Sample Output:

50
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int pal(string &str, int i, int j, vector<vector<int> > &dp){
    if(i==j)
        return 1;
    else if(i>j){
        return 0;
    }else{
        if(dp[i][j] != -1){
            return dp[i][j];
        }else{
            if(str[i] == str[j]){
                dp[i][j] = 2 + pal(str,i+1,j-1,dp);
            }else{
                dp[i][j] = max(pal(str,i+1,j,dp),pal(str,i,j-1,dp));
            }
        }
    }
    return dp[i][j];
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    string str;
    cin >> str;
    int len = str.size();
    vector<int> vec(len,0);
    vector<vector<int> > dp(len,vector<int>(len,-1));
    for(int i=0; i<len; i++){
        int l = pal(str,0,i,dp);        
        int r = pal(str,i+1,len-1,dp);        
        vec[i] = l*r;
    }
    cout << *max_element(vec.begin(),vec.end()) << endl;
    return 0;
}
