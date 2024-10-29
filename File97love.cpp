// Cycle Detection in Directed Graph using DFS

/*
Q.1. You are given a directed graph having ‘N’ nodes. A matrix ‘EDGES’ of size M x 2 is given 
which represents the ‘M’ edges such that there is an edge directed from node EDGES[i][0] to 
node EDGES[i][1].

Find whether the graph contains a cycle or not, return true if a cycle is present in the given 
directed graph else return false.

Note :
1. The cycle must contain at least two nodes.
2. It is guaranteed that the given graph has no self-loops in the graph.
3. The graph may or may not be connected.
4. Nodes are numbered from 1 to N.
5. Your solution will run on multiple test cases. If you are using global variables make sure to 
clear them.

Constraints :
1 ≤ T ≤ 5
2 <= N <= 100
1 <= M <= min(100,N(N-1)/2)
1 <= EDGES[i][0], EDGES[i][1] <= N

Where ‘T’ is the number of test cases.

Time Limit: 1 sec
Sample Input 1 :
1
5
6
1 2
4 1
2 4
3 4
5 2
1 3
Sample Output 1 :
true
Explanation For Input 1 :
The given graph contains cycle 1 -> 3 -> 4 -> 1 or the cycle 1 -> 2 -> 4 -> 1.
Sample Input 2 :
2
5
4
1 2
2 3
3 4
4 5
2
1
1 2
Sample Output 2 :
false
false
Explanation For Input 2 :
The given graphs don’t contain any cycle.
*/

/*
// Solution of question 1:-
// Time Complexity = O(n + e) where n and e are number of nodes and edges.

bool checkCycleDFS(int node, unordered_map<int, bool> &visited, unordered_map<int, bool> &dfsVisited , unordered_map<int, list<int> > &adj)
{
    visited[node] = true;
    dfsVisited[node] = true;

    for(auto neighbour : adj[node])
    {
        if(!visited[neighbour])
        {
            bool cycleDetected = checkCycleDFS(neighbour, visited, dfsVisited, adj);
            if(cycleDetected)
            {
                return true;
            }
        }
        else if(dfsVisited[neighbour])
        {
            return true;
        }
    }

    dfsVisited[node] = false;
    return false;
}

int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {

    // create adj list
    unordered_map<int, list<int> > adj;
    for(int i = 0; i < edges.size(); i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;
        adj[u].push_back(v);
    }

    unordered_map<int, bool> visited;
    unordered_map<int, bool> dfsVisited;
    for(int i = 1; i <= n; i++)
    {
        if(!visited[i])
        {
            bool cycleFound = checkCycleDFS(i, visited, dfsVisited, adj);
            if(cycleFound)
            {
                return true;
            }
        }
    }
    return false;
}
*/