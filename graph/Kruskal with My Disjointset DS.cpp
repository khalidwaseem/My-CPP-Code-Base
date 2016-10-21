/*
Kruskal with MY Disjointset Datastructure
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

/*********************** Disjoint-set Data structure ****************************/
void create_set(vector<int> &p,vector<int> &r, int x){
    p[x] = x;
    r[x] = 0;
}

int find_set(vector<int> &p, int x){
    if(x!=p[x]){
        p[x] = find_set(p,p[x]);
    }
    return p[x];
}

void merge_sets(vector<int> &p,vector<int> &r, int x, int y){
    int px = find_set(p,x);
    int py = find_set(p,y);
    
    if(r[px]>r[py]){
        p[py] = px;
    }else{
        p[px] = py;
    }
    if(r[px]==r[py]){
        r[py]++;
    }
}
/*********************** END Disjoint-set Data structure ****************************/

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int N,M,S;
    int u,v,r;

    cin >> N >> M;
    vector<pair<int,pair<int,int>>> edgeList;
    for(int i=0; i<M; i++){
        cin >> u >> v >> r;
        edgeList.push_back(make_pair(r,make_pair(u,v)));
    }
    cin >> S;

    sort(edgeList.begin(),edgeList.end());
    
    long long int mst = 0;

    /*********** Disjoint set Datastructure *****************/
    vector<int> parent(N+1,0);
    vector<int> rank(N+1,0);
    for(int i=1; i<N+1; i++){
       create_set(parent,rank,i);
    }
    /*********** END Disjoint set Datastructure *************/
    

    while(edgeList.size()){
        pair<int,pair<int,int>> edge = *edgeList.begin();
        int weight = edge.first;
        int u = edge.second.first;
        int v = edge.second.second;
        
        edgeList.erase(edgeList.begin());
        
        if(find_set(parent,u)!=find_set(parent,v)){
            mst += weight;
            merge_sets(parent,rank,u,v);           
        }
    }

    cout << mst << endl;

    return 0;
}
