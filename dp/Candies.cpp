/*Alice is a kindergarden teacher. She wants to give some candies to the children in her class.  All the children sit in a line ( their positions are fixed), 
and each  of them has a rating score according to his or her performance in the class.  Alice wants to give at least 1 candy to each child. 
If two children sit next to each other, then the one with the higher rating must get more candies. Alice wants to save money, so she needs to minimize 
the total number of candies given to the children.

*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int getcan(vector<int> &a, vector<int> &can, int i) {
    if(a[i]<=a[i-1] && a[i]<=a[i+1]) {
    	return 1;
    }
    if(a[i]>a[i-1] && a[i]<=a[i+1]) {
        if(can[i-1] == 0) 
        	can[i-1] = getcan(a,can,i-1);
        return 1 + can[i-1];
    }
    if(a[i]>a[i+1] && a[i]<=a[i-1]) {
        if(can[i+1] == 0) 
        	can[i+1] = getcan(a,can,i+1);
        return 1 + can[i+1];
    }
    if(a[i]>a[i+1] && a[i]>a[i-1]) {
        if(can[i-1] == 0) 
        	can[i-1] = getcan(a,can,i-1);
        if(can[i+1]==0) 
        	can[i+1] = getcan(a,can,i+1);
        return 1 + max(can[i-1] , can[i+1]);
    }
    return 0;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n,0), can(n,0);
    
    // Input
    for(int i=0;i<n;i++) { 
    	cin>>a[i];
    }
    
   
    // Boundry Condition
    can[0] = 1;
    can[n-1] = 1;
    if(a[0] > a[1]) 
    	can[0] = getcan(a,can,1) + 1;
    if(a[n-1] > a[n-2]) 
    	can[n-1] = getcan(a,can,n-2) + 1;
    
    for(int i=1;i<n-1;i++){
        if(can[i] == 0) 
        	can[i] = getcan(a,can,i);
    }

    unsigned long long result=0;
    for(int i=0;i<n;i++){
        result = result + can[i];
    }

    cout<<result;
    return 0;
}
