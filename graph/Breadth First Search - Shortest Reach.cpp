/*
Consider an undirected graph consisting of n nodes where each node is labeled from 1 to n 
and the edge between any two nodes is always of length 6. We define node s to be the 
starting position for a BFS.

Given q queries in the form of a graph and some starting node, s, perform each query by 
calculating the shortest distance from starting node s to all the other nodes in the graph. 
Then print a single line of n-1 space-separated integers listing node s's shortest distance 
to each of the n-1 other nodes (ordered sequentially by node number); if s is disconnected 
from a node, print -1 as the distance to that node.

Input Format

The first line contains an integer, q, denoting the number of queries. The subsequent lines 
describe each query in the following format:

- The first line contains two space-separated integers describing the respective values of 
n (the number of nodes) and m (the number of edges) in the graph.
- Each line i of the m subsequent lines contains two space-separated integers, u and v, 
describing an edge connecting node u to node v.
- The last line contains a single integer, s, denoting the index of the starting node.

Output Format

For each of the q queries, print a single line of n-1 space-separated integers denoting 
the shortest distances to each of the n-1 other nodes from starting position s. These 
distances should be listed sequentially by node number (i.e., 1,2,...,n), but should not 
include node s. If some node is unreachable from s, print -1 as the distance to that node.

Sample Input

2
4 2
1 2
1 3
1
3 1
2 3
2

Sample Output

6 6 -1
-1 6
*/

// BFS O(V+E)

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int Q;
    cin >> Q;
    for(int q=0; q<Q; q++){
        int N,M;
        int u,v;
        int S;
        cin >> N >> M;
        vector<vector<int> > adjList(N);
        
        for(int m=0; m<M; m++){
            cin >> u >> v;
            adjList[u-1].push_back(v);
            adjList[v-1].push_back(u);
        }
        cin  >> S;
        
        // Queue, Visited and Dist
        vector<int> visited(N,0), dist(N,0);
        queue<int> myQ;
        visited[S-1] = 1;
        dist[S-1] = 0;
        myQ.push(S);
        
        while(!myQ.empty()){
            int node = myQ.front();
            myQ.pop();
            
            for(int i=0; i<adjList[node-1].size(); i++){
                int child = adjList[node-1][i];
                if(visited[child-1] != 1){
                    visited[child-1] = 1;
                    dist[child-1] = dist[node-1] + 6;
                    myQ.push(child);
                }
            }
        }
        
        // Print
        for(int i=0; i<N; i++){
            if(i!=S-1){
                if(dist[i] == 0){
                    cout << "-1" << " ";
                }else{
                cout << dist[i] << " ";    
                }             
            }           
        }
        cout << endl;
        
        adjList.clear();
        visited.clear();
        dist.clear();
        
        /*// Print
        for(int i=0; i<N; i++){
            for(int j=0; j<adjList[i].size(); j++){
                cout << adjList[i][j] << " ";
            }
            cout << endl;
        }*/
    }
    return 0;
}
