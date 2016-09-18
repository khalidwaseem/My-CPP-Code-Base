/*
Sherlock Holmes suspects his archenemy, Professor Moriarty, is once again plotting something diabolical. 
Sherlock's companion, Dr. Watson, suggests Moriarty may be responsible for MI6's recent issues with 
their supercomputer, The Beast.

Shortly after resolving to investigate, Sherlock receives a note from Moriarty boasting about infecting 
The Beast with a virus; however, he also gives him a clue—a number, N. Sherlock determines the key to 
removing the virus is to find the largest Decent Number having N digits.

A Decent Number has the following properties:

1) Its digits can only be 3's and/or 5's.
2) The number of 3's it contains is divisible by 5.
3) The number of 5's it contains is divisible by 3.
4) If there are more than one such number, we pick the largest one.

Moriarty's virus shows a clock counting down to The Beast's destruction, and time is running out fast. 
Your task is to help Sherlock find the key before The Beast is destroyed!

Input Format

The first line is an integer, T, denoting the number of test cases.

The T subsequent lines each contain an integer, N, detailing the number of digits in the number.

Output Format

Print the largest Decent Number having N digits; if no such number exists, tell Sherlock by printing -1.

Sample Input

4
1
3
5
11

Sample Output

-1
555
33333
55555533333
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;


int main(){
    int T;
    cin >> T;
    for(int t=0; t<T; t++){
        long int N;
        cin >> N;
        
        string num = "";
        
        while(N > 0){
            if(N < 3){
                num = "";
                break;
            }else if(N%3==0){
                num = "555" + num;
                N = N-3;
            }else{
                num = "33333" + num;
                N = N-5;
            }
        }
        if(num==""||N<0)
            cout << -1 << endl;
        else
            cout << num << endl;
    }
    return 0;
}
