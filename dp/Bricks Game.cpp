/* 
You and your friend decide to play a game using a stack consisting of N bricks. In this game, 
you can alternatively remove 1, 2 or 3 bricks from the top, and the numbers etched on the removed bricks 
are added to your score. You have to play so that you obtain the maximum possible score. It is given that your 
friend will also play optimally and you make the first move.

Input Format 
First line will contain an integer T i.e. number of test cases. There will be two lines corresponding to each test case: 
first line will contain a number N i.e. number of elements in the stack and next line will contain N numbers 
i.e. numbers etched on bricks from top to bottom.

Output Format 
For each test case, print a single line containing your maximum score.

Sample Input

2
5
999 1 1 1 0
5
0 1 1 1 999

Sample Output

1001
999

*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
# define ull unsigned long long

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int T;
    int N;
    cin >> T;
    for(int t=0;t<T;t++){
        cin >> N;
        vector<ull> vec(N,0);
        for(int i=0;i<N;i++){
            cin >> vec[i];
        }
        
        vector<ull> sumTable(N,0);
        vector<ull> dp(N,-1);
        ull val = 0;
        
        if(N<=3){
            for(int i=0; i<N; i++){
                val = val + vec[i];
            }
            cout << val << endl;
        }else{
            // Initialize sumTable
            sumTable[N-1] = vec[N-1];
            for(int i=N-2;i>=0;i--){
                sumTable[i] = sumTable[i+1] + vec[i];
            }
        
            // Boundry condition
            dp[N-1] = sumTable[N-1];
            dp[N-2] = sumTable[N-2];
            dp[N-3] = sumTable[N-3];
            ull min = 0;
            for(int i=N-4; i>=0; i--){
                dp[i+1]<dp[i+2]?(dp[i+1]<dp[i+3]?min=dp[i+1]:min=dp[i+3]):(dp[i+2]<dp[i+3]?min=dp[i+2]:min=dp[i+3]);
                dp[i] = sumTable[i] - min;
            }
        
            cout << dp[0] << endl;
        }
    } 
    return 0;
}