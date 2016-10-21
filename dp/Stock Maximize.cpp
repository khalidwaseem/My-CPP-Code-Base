/*
Your algorithms have become so good at predicting the market that you now know what the share price of Wooden Orange Toothpicks Inc. (WOT) will be for the next N days.

Each day, you can either buy one share of WOT, sell any number of shares of WOT that you own, or not make any transaction at all. What is the maximum profit you can obtain with an optimum trading strategy?

Input

The first line contains the number of test cases T. T test cases follow:

The first line of each test case contains a number N. The next line contains N integers, denoting the predicted price of WOT shares for the next N days.

Output

Output T lines, containing the maximum profit which can be obtained for the corresponding test case.

Sample Input

3
3
5 3 2
3
1 2 100
4
1 3 1 2

Sample Output

0
197
3

*/

#include <cmath>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
using namespace std;

#define ull unsigned long long

ull findMax(vector<ull> &vec){
    ull max = vec[0];
    for(int i=0; i<vec.size(); i++){
        if(vec[i] > max)
            max = vec[i];
    }
    return max;
}

ull calProfit(vector<ull> &vec){
    ull cost = 0;
    for(int i=0; i<vec.size()-1; i++){
        cost = cost + vec[i];
    }
    ull profit = (vec.size()-1)*vec[vec.size()-1] - cost;
    return profit;
}

int main(){
    int T,N;
    cin >> T;
    for(int t=0; t<T; t++){
        cin >> N;
        vector<ull> vec(N);
        vector<ull>::iterator itr;
        
        for(int i=0; i<N; i++){
            cin >> vec[i];
        }
        
        ull max = 0;
        ull profit = 0;
        
        while(vec.size() > 0){
            max = findMax(vec);
            itr = find(vec.begin(),vec.end(),max);
            vector<ull> temp(vec.begin(),itr+1);
            profit = profit + calProfit(temp);
            vec.erase(vec.begin(),itr+1);
        }
        
        /*//Print 
        for(int i=0; i<N; i++){
            cout << vec[i] << endl;
        }*/
        cout << profit << endl;
    }
}