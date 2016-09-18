/*
Little Priyanka visited a kids' shop. There are N toys and their weight is represented by 
an array W=[w1,w2,...,wN]. Each toy costs 1 unit, and if she buys a toy with weight w', 
then she can get all other toys whose weight lies between [w',w'+4] (both inclusive) free of cost.

Input Format

The first line contains an integer N i.e. number of toys.
Next line will contain N integers, w1,w2,...,wN, representing the weight array.

Output Format

Minimum units with which Priyanka could buy all of toys.

Sample Input

5
1 2 3 17 10

Sample Output

3
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int N;
    cin >> N;
    vector<int> vec(N);
    for(int i=0; i<N; i++){
        cin >> vec[i];
    }
    
    sort(vec.begin(),vec.end());
    
    int count = 1;
    int weight = vec[0]+4;
    for(int i=1; i<N; i++){
        if(vec[i] > weight){
            weight = vec[i]+4;
            count++;
        }
    }
    cout << count << endl;
    return 0;
}


