/*
An Introduction to the Longest Increasing Subsequence Problems

The task is to find the length of the longest subsequence in a given array of integers such that all elements of the 
subsequence are sorted in ascending order. For example, the length of the LIS for { 15, 27, 14, 38, 26, 55, 46, 65, 85 } is 6 
and the longest increasing subsequence is {15, 27, 38, 55, 65, 85}.

Input Format

In the first line of input, there is a single number N. 
In the next N lines input the value of a[i].

Output Format

In a single line, output the length of the longest increasing sub-sequence.

Sample Input

5
2
7
4
3
8

Sample Output

3

*/

// METHOD 1: O(n^2)

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int findMax(vector<int> &lic){
    int max = -1; 
    for(int i=0; i<lic.size(); i++){
        if(lic[i]>max)
            max = lic[i];
    }
    return max;
}

int main() {
    int n;
    cin >> n;
    vector<int> vec(n);
    
    // Input
    for(int i=0; i<n; i++){
        cin >> vec[i];
    }
    
    vector<int> lic(n);
    lic[0] = 1;
    for(int i=1; i<n; i++){
        int len = 0;
        for(int j=0; j<i; j++){
            if(vec[j] < vec[i]){
                if(lic[j] > len){
                    len = lic[j];
                }
            }
        }
        lic[i] = len + 1;
    }
    /*for(int i=0; i<n; i++){
        cout << lic[i] <<" ";
    }*/
    
    cout << findMax(lic) << endl;
    
    return 0;
}


// METHOD 2: O(NlogN)




