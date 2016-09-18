/*
Lena is preparing for an important coding competition that is preceded by N sequential preliminary 
contests. She believes in "saving luck", and wants to check her theory. Each contest is described 
by two integers, Li and Ti:

- Li is the amount of luck that can be gained by winning the contest. If Lena wins the contest, 
her luck balance will decrease by Li; if she loses it, her luck balance will increase by Li.
- Ti denotes the contest's importance rating. It's equal to 1 if the contest is important, 
and it's equal to 0 if it's unimportant.

If Lena loses no more than K important contests, what is the maximum amount of luck she can have 
after competing in all the preliminary contests? This value may be negative.

Input Format

The first line contains two space-separated integers, N (the number of preliminary contests) 
and K (the maximum number of important contests Lena can lose), respectively. 
Each line i of the N subsequent lines contains two space-separated integers, 
Li (the contest's luck balance) and Ti (the contest's importance rating), respectively.

Output Format

Print a single integer denoting the maximum amount of luck Lena can have after all the contests.

Sample Input

6 3
5 1
2 1
1 1
8 1
10 0
5 0

Sample Output

29

There are N=6 contests. Of these contests, 4 are important (so she cannot lose any more than K=3 of them). 
Lena maximizes her luck if she wins the 3rd important contest (where Li=1) and loses all of the other 
five contests for a total luck balance of 5+2+8+10+5-1=29.
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int N,K;
    cin >> N >> K;
    vector<int> vec;
    int L,T;
    long long int totalLuck = 0;
    
    for(int i=0; i<N; i++){
        cin >> L >> T;
        if(T == 1){
            vec.push_back(L);
        }else{
            totalLuck += L;
        }
    }
    
    sort(vec.rbegin(),vec.rend());
    
    for(int i=0; i<vec.size(); i++){
        if(K>0){
            totalLuck += vec[i];
            K--;
        }else{
            totalLuck -= vec[i];
        }
    }
    
    cout << totalLuck << endl;
    
    return 0;
}
