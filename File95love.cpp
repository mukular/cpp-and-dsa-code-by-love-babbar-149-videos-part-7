// Depth first search(DFS)

/*
Q.1. Given an undirected and disconnected graph G(V,E), containing V vertices 
and E edges, the information about edges is given using GRAPH matrix, where
i-th edge is between GRAPH[i][0] and GRAPH[i][1], print its DFS traversal.
Vertices are numbered from 0 to V-1.

Constraints:-
2 <= V <= 10^3
1 <= E <= (5*(10^3))
Time Limit: 1sec

Sample Input 1:
5 4
0 2
0 1
1 2
3 4
Sample Output 1:
2
0 1 2
3 4

Sample Input 2:
9 7
0 1
0 2
0 5
3 6
7 4
4 8
7 8
Sample Output 2:
3
0 1 2 5
3 6
4 7 8
*/

/*
// Solution of question 1:-

void dfs(int node, unordered_map<int, bool> &visited, unordered_map<int, list<int> > &adj, vector<int> &component)
{
    component.push_back(node);
    visited[node]= true;

    for(auto i: adj[node])
    {
        if(!visited[i])
        {
            dfs(i, visited, adj, component);
        }
    }
}

vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    unordered_map<int, list<int> > adj;
    for(int i = 0; i < edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<vector<int>> ans;
    unordered_map<int, bool> visited;

    for(int i = 0; i < V; i++)
    {
        if(!visited[i])
        {
            vector<int> component;
            dfs(i, visited, adj, component);
            ans.push_back(component);
        }
    }

    return ans;
}
*/