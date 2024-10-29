// Cycle detection in Undirected graph

/*
Q.1. You have been given an undirected graph with 'N' vertices and 'M' edges. The vertices are 
labelled from 1 to 'N'.
Your task is to find if the graph contains a cycle or not.
A path that starts from a given vertex and ends at the same vertex traversing the edges only 
once is called a cycle.

Note:

1. There are no parallel edges between two vertices.
2. There are no self-loops(an edge connecting the vertex to itself) in the graph.
3. The graph can be disconnected.
For Example :

Input: N = 3 , Edges =  [[1, 2], [2, 3], [1, 3]].
Output: Yes

Explanation : There are a total of 3 vertices in the graph. There is an edge between vertex 1 
and 2, vertex 2 and 3 and vertex 1 and 3. So, there exists a cycle in the graph. 

Constraints:
1 <= T <= 10
1 <= N <= 5000
0 <= M <= min(5000, (N * (N - 1)) / 2)
1 <= edges[i][0] <= N 
1 <= edges[i][1] <= N 

Time Limit: 1 sec 
Sample Input 1:
1
3 2
1 2
2 3
Sample output 1:
No
Explanation of Sample output 1:

There are a total of 3 vertices in the graph.There is an edge between vertex 1 and 2 and 
vertex 2 and 3. So, there is no cycle present in the graph. 
Sample Input 2:
2
4 0 
4 3
1 4
4 3
3 1
Sample output 2:
No
Yes
*/

/*
// Solution of question 1(Using BFS):-

bool isCyclicBFS(int src, unordered_map<int, bool> &visited, unordered_map<int, list<int> > &adj)
{
    unordered_map<int, int> parent;
    parent[src] = -1;
    visited[src] = 1;
    queue<int> q;
    q.push(src);

    while(!q.empty())
    {
        int front = q.front();
        q.pop();

        for(auto neighbour : adj[front])
        {
            if(visited[neighbour] == true && neighbour != parent[front])
            {
                return true;
            }
            else if(!visited[neighbour])
            {
                q.push(neighbour);
                visited[neighbour] = 1;
                parent[neighbour] = front;
            }
        }
    }
    return false;
}

string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    // create adjacency list
    unordered_map<int, list<int> > adj;
    for(int i = 0; i < m; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    unordered_map<int, bool> visited;
    for(int i = 0; i < n; i++)
    {
        if(!visited[i])
        {
            bool ans = isCyclicBFS(i, visited, adj);
            if(ans == 1)
            {
                return "Yes";
            }
        }
    }

    return "No";
}
*/


/*
// Solution of question 1(Using DFS):-

bool isCyclicDFS(int node, int parent, unordered_map<int, bool> &visited, unordered_map<int, list<int> > &adj)
{
    visited[node] = true;

    for(auto neighbour : adj[node])
    {
        if(!visited[neighbour])
        {
            bool cycleDetected = isCyclicDFS(neighbour, node, visited, adj);
            if(cycleDetected)
            {
                return true;
            }
        }
        else if(neighbour != parent)
        {
            return true;
        }
    }
    return false;
}

string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    // create adjacency list
    unordered_map<int, list<int> > adj;
    for(int i = 0; i < m; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    unordered_map<int, bool> visited;
    for(int i = 0; i < n; i++)
    {
        if(!visited[i])
        {
            bool ans = isCyclicDFS(i, -1, visited, adj);
            if(ans == 1)
            {
                return "Yes";
            }
        }
    }

    return "No";
}
*/