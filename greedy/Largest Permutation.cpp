/*
You are given an array of N integers which is a permutation of the first N natural numbers. 
You can swap any two elements of the array. You can make at most K swaps. What is the 
largest permutation, in numerical order, you can make?

Input Format 
The first line of the input contains two integers, N and K, the size of the input array 
and the maximum swaps you can make, respectively. The second line of the input contains a 
permutation of the first N natural numbers.

Output Format 
Print the lexicographically largest permutation you can make with at most K swaps.

Sample Input#00

5 1
4 2 3 5 1

Sample Output#00

5 2 3 4 1
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define lli long long int

int main() {
    
    int N;
    lli K;
    cin >> N >> K;
    vector<int> vec(N+1);
    vector<int> index(N+1);
    
    for(int i=1; i<=N; i++){
        cin >> vec[i];
        index[vec[i]] = i;
    }
    
    for(int i=1; i<=N; i++){
        if(vec[i] == N-i+1){
            continue;
        }
        if(K>0){
            vec[index[N-i+1]] = vec[i];
            index[vec[i]] = index[N-i+1];
            vec[i] = N-i+1;
            index[N-i+1] = i;
            K--;
        }else{
            break;
        }
    }
    
    for(int i=1; i<=N; i++){
        cout << vec[i] << " ";
    }
    
    return 0;
}
