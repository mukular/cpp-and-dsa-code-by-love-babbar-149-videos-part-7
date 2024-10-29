// Graph

/*
Some terms :-
1. undirected graph - Edges bidirectional hogi
2. Directed graph - Edges ki direction hogi
3. Node - Entity To store data
4. Edges - connect nodes
5. degree of node b(in case of undirected graph) - Means number of nodes connected to b
6. Indegree of node b(in case of directed graph) - Means b ki taraf kitni edges aa rahi h
7. Outdegree of node b(in case of directed graph) - Means b se kitni edges bahar nikal rahi h
8. Weighted graph - Edges par weight hoga(If not given then assume weight to be 1)

*/

#include<iostream>
#include<unordered_map>
#include<list>
using namespace std;
template <typename T>

class graph{
    public:
    unordered_map<T, list<T> > adj;

    void addEdge(T u, T v, bool direction)
    {
        // direction = 0 means undirected
        // direction = 1 means directed

        // create an edge from u to v
        adj[u].push_back(v);
        if(direction == 0)
        {
            adj[v].push_back(u);
        }
    }

    void printAdjList()
    {
        for(auto i : adj)
        {
            cout<<i.first<<"-> ";
            for(auto j : i.second)
            {
                cout<<j<<", ";
            }
            cout<<endl;
        }
    }
};

int main()
{
    // Input :-
    // 5 6 0 1 1 2 2 3 3 1 3 4 0 4
    int n;
    cout<<"Enter the number of nodes"<<endl;
    cin>>n;
    int m;
    cout<<"Enter the number of edges "<<endl;
    cin>>m;

    graph<int> g;

    for(int i = 0; i < m; i++)
    {
        int u, v;
        cin>>u>>v;
        // creating an undirected graph
        g.addEdge(u, v, 0);
    }

    // printing graph
    g.printAdjList();
    return 0;
}

/*
Q.1. You are given an undirected graph of N nodes and M edges. Your task is to
create the graph and print the adjacency list of the graph.It is guaranteed
that all the edges are unique, i.e. if there is an edge from X to Y, then there
is no edge present from Y to X and vice versa.Also, there are no self-loops present
in the graph.
In graph theory, an adjacency list is a collection of unordered lists used to 
represent a finite graph.Each list describes the set of neighbors of a vertex in the graph.

Sample Input 1:
4 3
1 2
0 3
2 3
Sample Output 1:
0 3
1 2
2 1 3
3 0 2

Sample Input 2:
3 3
0 1
1 2
2 0
Sample Output 2:
0 1 2
1 0 2
2 0 1

Constraints:
1 <= N <= 5000
1 <= M <= min(5000, (N * (N - 1)) / 2)
0 <= edges[i][0], edges[i][1] <= N-1

Time limit: 1 sec
*/

/*
// Solution of question 1:-

vector < vector < int >> printAdjacency(int n, int m, vector < vector < int >> & edges) {
    vector<int> ans[n];
    for(int i = 0; i < m; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        ans[u].push_back(v);
        ans[v].push_back(u);
    }

    vector<vector<int> > adj(n);
    for(int i = 0; i < n; i++)
    {
        adj[i].push_back(i);
        for(int j = 0; j < ans[i].size(); j++)
        {
            adj[i].push_back(ans[i][j]);
        }
    }

    return adj;
}
*/