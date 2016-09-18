/*
Mark and Jane are very happy after having their first kid. Their son is very fond of toys, 
so Mark wants to buy some. There are N different toys lying in front of him, tagged with 
their prices, but he has only $K. He wants to maximize the number of toys he buys with this money.

Now, you are Mark's best friend and have to help him buy as many toys as possible.

Input Format 
The first line contains two integers, N and K, followed by a line containing N space separated 
integers indicating the products' prices.

Output Format 
An integer that denotes maximum number of toys Mark can buy for his son.

Sample Input

7 50
1 12 5 111 200 1000 10

Sample Output

4
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define lli long long int

int main() 
{
    int N;
    lli K;
    cin >> N >> K;
    vector<lli> vec(N);
    
    for(int i=0; i<N; i++){
        cin >> vec[i]; 
    }
    sort(vec.begin(),vec.end());
    int count = 0;
    lli sum = 0;
    for(int i=0; i<N; i++){
        sum = sum+vec[i];
        if(sum <= K){
            count++;            
        }else{
            break;
        }
    }
    cout << count << endl;
    return 0;
}
