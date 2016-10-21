/*
Given an undirected weighted connected graph, it is required to find the Really Special 
SubTree in it. The Really Special SubTree is defined as a subgraph consisting of all the 
nodes in the graph and

- There is only one exclusive path from a node to every other node.
- The subgraph is of minimum overall weight (sum of all edges) among all such subgraphs.
- While creating the Really Special SubTree, start by picking the edge with smallest weight. 
- If there are edges of equal weight available at an instant, then the edge to be chosen first 
among them is the one with minimum value of sum of the following expression :
 - u + wt + v , where u and v are the node numbers of the corresponding edge and wt is the weight.
- Even then if there is a collision, choose any one of them.
- While doing the above, ensure that no cycle is formed while picking up edges.

Finally, you need to print the overall weight of the Christmas Tree so formed using above rules.

Input Format

First line has two integers N, denoting the number of nodes in the graph and M, denoting the number 
of edges in the graph.

The next M lines each consist of three space separated integers x y r, where x and y denote the 
two nodes between which the undirected edge exists, r denotes the weight of edge between the 
corresponding nodes.

The last line has an integer S, denoting the starting node.

If there are edges between the same pair of nodes with different weights, they are to be considered 
as is, like multiple edges.

Output Format

Print a single integer denoting the total weight (sum of weights of all edges in the MST) of the 
Really Special SubTree.

Sample Input

4 6
1 2 5
1 3 3
4 1 6
2 4 7
3 2 4
3 4 5
1

Sample Output

12
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
        if(edgeList.size()>1){
            pair<int,pair<int,int>> adjEdge = *(edgeList.begin()+1);
            if(adjEdge.first == weight){
                int adjWeight = adjEdge.first;
                int adjU = adjEdge.second.first;
                int adjV = adjEdge.second.second;
                if(adjU+adjWeight+adjV < u+weight+v){
                    u = adjU;
                    v = adjV;
                    weight = adjWeight;
                    edgeList.erase(edgeList.begin()+1);
                }else{
                    edgeList.erase(edgeList.begin());
                }
            }else{
                edgeList.erase(edgeList.begin());
            }
        }else{
            edgeList.erase(edgeList.begin());
        }

        if(find_set(parent,u)!=find_set(parent,v)){
            mst += weight;
            merge_sets(parent,rank,u,v);           
        }
    }

    cout << mst << endl;

    return 0;
}
