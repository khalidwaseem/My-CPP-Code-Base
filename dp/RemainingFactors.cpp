/*Eric is a mischievous lad. He loves troubling his teachers. One day his maths teacher, Mr. Kakutani decided to punish Eric by giving him a problem. 
The problem read as follows : "Given a positive integer N, find the number of positive integer divisors of N2 that are less than N, but do not divide N."
Can you solve the problem for Eric?*/


#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#include <iterator>

#define tr(c,i) for(decltype(c.begin()) i=c.begin(); i!=c.end(); i++)
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    unsigned long long N;
    cin >> N;
    set<unsigned long long> facN,tempfacN,facN2;
    //set<unsigned long long>::iterator itr;
    
    for(unsigned long long i=1; i <= N/2; i++){
        if(N%i == 0){
            if(facN.find(i) == facN.end() && facN.find(N/i) == facN.end()){
                facN.insert(i);
                if(N/i != N)
                    facN.insert(N/i);
            }else{
                break;
            }
        }
    }
    
    tempfacN = facN;
    
    tr(facN,itr){
        //cout << *itr << endl;
        tr(tempfacN,tempitr){
            unsigned long long fact = (*itr)*(*tempitr);
            if((fact < N) && (N%fact != 0)){
                facN2.insert(fact);
            }
        }
    }
    
    /*tr(facN2,itr){
        //cout << *itr << endl;
        if(N%(*itr) == 0){
            facN2.erase(itr);
        }
    }*/
    
    /*tr(facN2,itr){
        cout << *itr << endl;
    }*/
    cout << facN2.size();
    
    return 0;
}
