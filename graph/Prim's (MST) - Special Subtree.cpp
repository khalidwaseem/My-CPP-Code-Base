/*
Given a graph which consists of several edges connecting the N nodes in it. 
It is required to find a subgraph of the given graph with the following properties:

- The subgraph contains all the nodes present in the original graph.
- The subgraph is of minimum overall weight (sum of all edges) among all such subgraphs.
- It is also required that there is exactly one, exclusive path between any two nodes 
of the subgraph.

One specific node S is fixed as the starting point of finding the subgraph. 
Find the total weight of such a subgraph (sum of all edges in the subgraph)

Input Format

First line has two integers N, denoting the number of nodes in the graph and M, denoting 
the number of edges in the graph.

The next M lines each consist of three space separated integers x y r, where x and y 
denote the two nodes between which the undirected edge exists, r denotes the length of 
edge between the corresponding nodes.

The last line has an integer S, denoting the starting node.

If there are edges between the same pair of nodes with different weights, they are to be 
considered as is, like multiple edges.

Output Format

Print a single integer denoting the total weight of tree so obtained (sum of weight of edges).

Sample Input

5 6
1 2 3
1 3 4
4 2 6
5 2 2
2 3 5
3 5 7
1

Sample Output

15
*/

// O(ElogV)

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

#define INF numeric_limits<int>::max()

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int N,M,S;
    int u,v,r;
    
    cin >> N >> M;
    vector<vector<int> > adjList(N);
    vector<vector<int> > minEdge(N, vector<int>(N,INF));
    for(int i=0; i<M; i++){
        cin >> u >> v >> r;
        if(minEdge[u-1][v-1] == INF){
            adjList[u-1].push_back(v);
            adjList[v-1].push_back(u);
            minEdge[u-1][v-1] = r;
            minEdge[v-1][u-1] = r;
        }else if(minEdge[u-1][v-1] > r){
            minEdge[u-1][v-1] = r;
            minEdge[v-1][u-1] = r;
        }
    }
    cin >> S;
    
    set<pair<int,int> > mySet;
    vector<int> visited(N,0);
    vector<int> key(N,INF);
    mySet.insert(make_pair(0,S));
    visited[S-1] = 1;
    key[S-1] = 0;
    
    long long int mst = 0;
    while(!mySet.empty()){
        pair<int,int> node = *mySet.begin();
        mySet.erase(mySet.begin());
        int u = node.second;
        int weightU = node.first;
        visited[u-1] = 1;
        mst = mst+weightU; 
        
        for(int i=0; i<adjList[u-1].size(); i++){
            int v = adjList[u-1][i];
            int weightV = minEdge[u-1][v-1];
            if(visited[v-1] == 0){
                if(key[v-1] == INF){
                key[v-1] = weightV;
                mySet.insert(make_pair(weightV,v));
                } else if(key[v-1] > weightV){
                    mySet.erase(make_pair(key[v-1],v));
                    key[v-1] = weightV;
                    mySet.insert(make_pair(key[v-1],v));    
                }    
            }        
        }
    }
    
    cout << mst << endl;
    
    return 0;
}
