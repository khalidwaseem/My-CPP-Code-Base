/*
How many different ways can you make change for an amount, given a list of coins? In this problem, your code will need to efficiently compute the answer.

Task

Write a program that, given

- The amount N to make change for and the number of types M of infinitely available coins
- A list of  coins - C = {C1, C2, C3, ... , Cm} 
Prints out how many different ways you can make change from the coins to STDOUT.

The problem can be formally stated:

Given a value N, if we want to make change for N cents, and we have infinite supply of each of C={C1,C2,C3,...,Cm} valued coins, how many ways can we make the change? The order of coins doesn’t matter.

Input Format

First line will contain 2 integer N and M respectively. 

Second line contain M integer that represent list of distinct coins that are available in infinite amount.

Output Format

One integer which is the number of ways in which we can get a sum of N from the given infinite supply of M types of coins.

Sample Input

4 3
1 2 3 
Sample Output

4


*/




#include<iostream>
#include<stdio.h>
#include<vector>
#include<sstream>
#include<iterator>
#include<map>
#include<utility>

using namespace std;

map< pair<int, int> , long long> myMap;

long long calculate(vector<int> vec, int m, int n) {
	if (vec.empty() && n > 0) {
		return 0;
	} else if (n < 0) {
		return 0;
	} else if (n == 0) {
		return 1;
	} else {
		long long lc, rc;
		int coin = vec.front();

		pair<int, int> pr(m,n-coin);
		if (myMap.find(pr) != myMap.end()) {
			lc = myMap[pr];
		}else {
			lc = calculate(vec, m, n - coin);
		}

		vec.erase(vec.begin()+0);
		pair<int, int> pr1(m-1, n);
		if (myMap.find(pr1) != myMap.end()) {
			rc = myMap[pr1];
		}else {
			rc = calculate(vec, m-1, n);
		}

		pair<int, int> pr2(m, n);
		myMap[pr2] = lc + rc;

		return lc + rc;
	}
}

int main() {

int n, m, coin;
vector<int> vec;
cin >> n >> m;

for (int i = 0; i < m; i++) {
cin >> coin;
vec.push_back(coin);
}

cout << calculate(vec, m, n) << endl;

return 0;
}