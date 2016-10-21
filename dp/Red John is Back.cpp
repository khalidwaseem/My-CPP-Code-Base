/*
Red John has committed another murder. But this time, he doesn't leave a red smiley behind. What he leaves behind is a puzzle for Patrick Jane to solve. He also texts Teresa Lisbon that if Patrick is successful, he will turn himself in. The puzzle begins as follows.

There is a wall of size 4xN in the victim's house. The victim also has an infinite supply of bricks of size 4x1 and 1x4 in her house. There is a hidden safe which can only be opened by a particular configuration of bricks in the wall. In every configuration, the wall has to be completely covered using the bricks. There is a phone number written on a note in the safe which is of utmost importance in the murder case. Gale Bertram wants to know the total number of ways in which the bricks can be arranged on the wall so that a new configuration arises every time. He calls it M. Since Red John is back after a long time, he has also gained a masters degree in Mathematics from a reputed university. So, he wants Patrick to calculate the number of prime numbers (say P) up to M (i.e. <= M). If Patrick calculates P, Teresa should call Red John on the phone number from the safe and he will surrender if Patrick tells him the correct answer. Otherwise, Teresa will get another murder call after a week.

You are required to help Patrick correctly solve the puzzle.

Input Format

The first line of input will contain an integer T followed by T lines each containing an integer N.

Output Format

Print exactly one line of output for each test case. The output should contain the number P.

Sample Input

2
1
7
Sample Output

0
3

*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define ull unsigned long long

/*unsigned long long findTotalPrimes(unsigned long long M){
    if(M == 1)
        return 0;
    else {
        int count = 0;
        int divflag = 0;
        for(int i=2; i<=M; i++){
            divflag = 0;
            for(int j=2; j<=i/2; j++){
                if(i%j == 0){
                    divflag = 1;
                    break;
                }                    
            }
            if(divflag == 0)
                count++;
        }
        return count;
    }
}*/

/*unsigned long long SieveOfEratosthenes(unsigned long long n)
{
    // Create a boolean array "prime[0..n]" and initialize
    // all entries it as true. A value in prime[i] will
    // finally be false if i is Not a prime, else true.
    vector<int> prime(n+1,1);
 
    for (unsigned long long p=2; p*p<=n; p++)
    {
        // If prime[p] is not changed, then it is a prime
        if (prime[p] == 1)
        {
            // Update all multiples of p
            for (unsigned long long i=p*2; i<=n; i += p)
                prime[i] = 0;
        }
    }
 
    // Print all prime numbers
    unsigned long long count = 0;
    for (unsigned long long p=2; p<=n; p++)
       if (prime[p])
          count++;
        
    return count;
}*/

unsigned long long SieveOfEratosthenes(unsigned long long n){
    vector<unsigned long long> a(n+1,1);
    for(ull i=2; i*i<=n; i++){
        if(a[i] == 1){
            for(ull j=2*i; j<=n; j=j+i)
                a[j] = 0;
        }
    }
    
    ull count = 0;
    for(ull i=2; i<=n; i++){
        if(a[i] == 1)
            count++;
    }
    return count;
}

/*unsigned long long fact(unsigned long long n){
    unsigned long long f = 1;
    if(n == 0 || n == 1)
        return f;
    else{
        for(unsigned long long i=n; i>1; i--){
            f = f * i; 
        }
    }
    return f;
}*/

/*unsigned long long calcM(vector<unsigned long long> &table, unsigned long long N){
    if(N == 0 || N==1 || N==2 || N==3)
        return N;
    else{
        return
    }
}*/

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int T;
    cin >> T;
    unsigned long long N,M,P;
    //unsigned long long noFour, noOne;
    for(int i=0; i<T; i++){
        cin >> N;
        vector<unsigned long long> table(N+1,0);
        //M = calcM(table,N);
        //M = 0;
        for(int j=0; j<=N; j++){
            if(j == 0 || j==1 || j==2 || j==3){
                table[j] = 1;
            }else{
                table[j] = table[j-1] + table[j-4];
            }        
        }
        M = table[N];
        P = SieveOfEratosthenes(M);
        cout << P << endl;
    }
    return 0;
}
