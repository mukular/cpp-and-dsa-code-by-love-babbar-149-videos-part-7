// Prim's algorithm to find minimum spanning tree

// Spanning Tree :- When you convert graph into a tree such that it contains n nodes and n-1 edges
// and every node is reachable by every other node. Doesn't have cycle also.

// For the minimum spanning tree means minimum cost of weights

/*
Q.1. You are given an undirected connected weighted graph having ‘N’ nodes numbered from 1 to 'N'. A matrix ‘E’ of 
size M x 2 is given which represents the ‘M’ edges such that there is an edge directed from node E[i][0] to node E[i][1]. 
You are supposed to return the minimum spanning tree where you need to return weight for each edge in the MST.

Constraints :
1 ≤ T ≤ 5
2 <= N <= 100
1 <= M <= min(1000, N(N - 1) / 2)
1 <= E[i][0], E[i][1] <= N

Time Limit: 1 sec
Sample Input 1 :
1
5 14
1 2 2
1 4 6
2 1 2
2 3 3
2 4 8
2 5 5
3 2 3
3 5 7
4 1 6
4 2 8
4 5 9
5 2 5
5 3 7
5 4 9
Sample Output 1 :
1 2 2
1 4 6
2 3 3
2 5 5
Explanation of Input 1 :
The Minimum spanning tree for the given graph will contain the edges: (1,2) with weight 2, (1,4) with weight 6, (2,3) 
with weight 3 and (2,5) with weight 5.
Sample Input 2 :
1
5 15
1 2 21
1 4 16
2 1 12
2 3 13
2 4 18
2 5 15
3 2 13
3 5 17
4 1 16
4 2 18
4 5 19
5 1 18
5 2 15
5 3 17
5 4 19
Sample Output 2 :
1 2 12
1 4 16
2 3 13
2 5 15
Explanation of Input 2 :
The Minimum spanning tree for the given graph will contain the edges: (1,2) with weight 12, (1,4) with weight 16, 
(2,3) with weight 13 and (2,5) with weight 15.
*/

/*
// Solution of question 1 :-
// Time Complexity = O(n^2)  // can be optimised using priority queue then time complexity will be O(n*log(n))

#include <bits/stdc++.h> 
vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    unordered_map<int, list<pair<int, int> > > adj;

    for(int i = 0; i < g.size(); i++)
    {
        int u = g[i].first.first;
        int v = g[i].first.second;
        int w = g[i].second;
        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }

    vector<int> key(n+1);
    vector<bool> mst(n+1);
    vector<int> parent(n+1);

    for(int i = 0; i <= n; i++)
    {
        key[i] = INT_MAX;
        parent[i] = -1;
        mst[i] = false;
    }

    key[1] = 0;
    parent[1] = -1;

    for(int i = 1; i < n; i++)
    {
        int mini = INT_MAX;
        int u;

        for(int v = 1; v <= n; v++)
        {
            if(mst[v] == false && key[v] < mini)
            {
                u = v;
                mini = key[v];
            }
        }

        mst[u] = true;

        for(auto it : adj[u])
        {
            int v = it.first;
            int w = it.second;

            if(mst[v] == false && w < key[v])
            {
                parent[v] = u;
                key[v] = w;
            }
        }
    }

    vector<pair<int, int>, int>> result;
    for(int i = 2; i <= n; i++)
    {
        result.push_back({{parent[i], i}, key[i]});
    }

    return result;

}

*/