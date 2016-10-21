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
struct DisjointSets
{
    int *parent, *rnk;
    int n;
 
    // Constructor.
    DisjointSets(int n)
    {
        // Allocate memory
        this->n = n;
        parent = new int[n+1];
        rnk = new int[n+1];
 
        // Initially, all vertices are in different sets and have rank 0.
        for (int i = 0; i <= n; i++)
        {
            rnk[i] = 0;
 
            //every element is parent of itself
            parent[i] = i;
        }
    }
 
    // Find the parent of a node 'u'
    // Path Compression
    int find(int u)
    {
        /* Make the parent of the nodes in the path from u--> parent[u] point to parent[u] */
        if (u != parent[u])
            parent[u] = find(parent[u]);
        return parent[u];
    }
 
    // Union by rank
    void merge(int x, int y)
    {
        x = find(x), y = find(y);
 
        /* Make tree with smaller height a subtree of the other tree  */
        if (rnk[x] > rnk[y])
            parent[y] = x;
        else // If rnk[x] <= rnk[y]
            parent[x] = y;
 
        if (rnk[x] == rnk[y])
            rnk[y]++;
    }
};
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
    DisjointSets ds(N);
    /*********** END Disjoint set Datastructure *************/
    

    while(edgeList.size()){
        pair<int,pair<int,int>> edge = *edgeList.begin();
        int weight = edge.first;
        int u = edge.second.first;
        int v = edge.second.second;
        
        edgeList.erase(edgeList.begin());
        
        if(ds.find(u)!=ds.find(v)){
            mst += weight;
            ds.merge(u,v);           
        }
    }

    cout << mst << endl;

    return 0;
}
