// Topological sort using BFS / Kahn's Algorithm
// Time Complexity = O(N+E)
// Space Complexity = O(N+E)
// where N and E are number of nodes and edges.

/*
Q.1. A Directed Acyclic Graph(DAG) is a directed graph that contains no cycles.
Topological Sorting of DAG is a linear ordering of vertices such that for every 
directed edge from vertex 'u' to vertex 'v', vertex 'u' comes before 'v' in the
ordering.Topological Sorting for a graph is not possible if the graph is not a DAG.
Given a DAG consisting of 'V' vertices and 'E' edges, you need to find out any topological
sorting of this DAG.Return an array of size 'V' representing the topological sort of the
vertices of the given DAG.

Constraints:-
1 <= T <= 50
1 <= V <= 10^4
0 <= E <= 10^4
0 <= u, v < V
where T is the total number of test cases, V is the number of vertices, E is the 
number of edges, and u and v both represent the vertex of a given graph.
Time limit: 2 sec

Sample Input 1:
2
2 1
1 0
3 2
0 1
0 2
Sample Output 1:
1 0
0 2 1

Sample Input 2:
2
1 0
4 4
0 1
0 3
1 2
3 2
Sample Output 2:
0
0 1 3 2
*/

/*
// Solution of question 1:-

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)
{
    unordered_map<int, list<int> > adj;
    for(int i = 0; i < e; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
    }

    vector<int> indegree(v);
    for(auto i: adj)
    {
        for(auto j: i.second)
        {
            indegree[j]++;
        }
    }

    queue<int> q;
    for(int i = 0; i < v; i++)
    {
        if(indegree[i] == 0)
        {
            q.push(i);
        }
    }

    vector<int> ans;
    while(!q.empty())
    {
        int front = q.front();
        q.pop();

        ans.push_back(front);

        for(auto neighbour : adj[front])
        {
            indegree[neighbour]--;
            if(indegree[neighbour] == 0)
            {
                q.push(neighbour);
            }
        }
    }

    return ans;
}
*/