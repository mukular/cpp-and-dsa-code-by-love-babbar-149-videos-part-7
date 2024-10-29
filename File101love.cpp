// Cycle detection in directed graph using BFS/Kahn's Algorithm
/*
Q.1. You are given a directed graph having N nodes.A matrix EDGES of
size M*2 is given which represents the M edges such that there is an 
edge directed from node EDGES[i][0] to node EDGES[i][1].
Find whether the graph contains a cycle or not, return true if a cycle 
is present in the given directed graph else return false.

Constraints:-
1 <= T <= 5
2 <= N <= 100
1 <= M <= min(100, N(N-1)/2)
1 <= EDGES[i][0], EDGES[i][1] <= N
where T is the number of test cases.
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
*/

/*
// Solution of question 1:-

int detectCycleInDirectedGraph(int n, vector<pair<int, int>> &edges)
{
    unordered_map<int, list<int> > adj;
    for(int i = 0; i < edges.size(); i++)
    {
        int u = edges[i].first -1;       // yeh -1 isliye kiya h taki nodes 0 se start ho
        int v = edges[i].second -1;
        adj[u].push_back(v);
    }

    vector<int> indegree(n);
    for(auto i: adj)
    {
        for(auto j: i.second)
        {
            indegree[j]++;
        }
    }

    queue<int> q;
    for(int i = 0; i < n; i++)
    {
        if(indegree[i] == 0)
        {
            q.push(i);
        }
    }

    int cnt = 0;
    while(!q.empty())
    {
        int front = q.front();
        q.pop();
        cnt++;

        for(auto neighbour : adj[front])
        {
            indegree[neighbour]--;
            if(indegree[neighbour] == 0)
            {
                q.push(neighbour);
            }
        }
    }

    if(cnt == n)
    {
        return false;
    }
    else
    {
        return true;
    }
}

*/

// Time Complexity = O(N+E)
// Space Complexity = O(N+E)
// where N and E are number of nodes and edges.