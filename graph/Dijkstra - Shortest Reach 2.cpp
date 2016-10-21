/*
Given a graph consisting N nodes (labelled 1 to N) where a specific given node S 
represents the starting position S and an edge between two nodes is of a given 
length, which may or may not be equal to other lengths in the graph.

It is required to calculate the shortest distance from the start position (Node S) 
to all of the other nodes in the graph.

Note: If a node is unreachable , the distance is assumed as -1.

Input Format

The first line contains T, denoting the number of test cases. 
First line of each test case has two integers N, denoting the number of nodes in 
the graph and M, denoting the number of edges in the graph.

The next M lines each consist of three space-separated integers x y r, where x and y 
denote the two nodes between which the undirected edge exists, r denotes the length 
of edge between these corresponding nodes.

The last line has an integer S, denoting the starting position.

If there are edges between the same pair of nodes with different weights, they are 
to be considered as is, like multiple edges.

Output Format

For each of the T test cases, print a single line consisting N-1 space separated 
integers denoting the shortest distance of N-1 nodes other than S from starting 
position S in increasing order of their labels.

For unreachable nodes, print -1.

Sample Input

1
4 4
1 2 24
1 4 20
3 1 3
4 3 12
1

Sample Output

24 3 15

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
    
    // For Large inputs turn off synchronization with the standard C stream objects:
    ios_base::sync_with_stdio(false);
    
    int Q;
    cin >> Q;
    for(int q=0; q<Q; q++){
        int N,M;
        int u,v,r;
        int S;
        cin >> N >> M;
        vector<vector<int> > adjList(N);
        vector<vector<int> > minEdge(N, vector<int>(N,INF));
        
        for(int m=0; m<M; m++){
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
        cin  >> S;
        
        vector<int> dist(N,INF);
        set<pair<int,int> > mySet;
        dist[S-1] = 0;
        mySet.insert(make_pair(0,S));
        
        while(!mySet.empty()){
            pair<int,int> node = *mySet.begin();
            mySet.erase(mySet.begin());
            int weightU = node.first;
            int u = node.second;
            
            for(int i=0; i<adjList[u-1].size(); i++){
                int v = adjList[u-1][i];
                int weightV = minEdge[u-1][v-1];
                if(dist[v-1] > weightU+weightV){
                    if(dist[v-1] == INF){
                        dist[v-1] = weightU+weightV;
                        mySet.insert(make_pair(dist[v-1],v));
                    }else{
                        mySet.erase(make_pair(dist[v-1],v));
                        dist[v-1] = weightU+weightV;
                        mySet.insert(make_pair(dist[v-1],v));
                    }
                }
            }
        }
        
        // Print
        for(int i=0; i<N; i++){
            if(i!=S-1){
                if(dist[i] == INF){
                    cout << "-1" << " ";
                }else{
                    cout << dist[i] << " ";
                }
            }
        }
        cout << endl;
        
    }
    return 0;
}
