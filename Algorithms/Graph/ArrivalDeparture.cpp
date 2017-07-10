#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

struct Edge
{
    int src;
    int dst;
};

struct Graph
{
    vector<vector<int> > adjList;
    
    Graph(vector<Edge>& edges)
    {
        adjList.resize(edges.size());
        
        // add edges for each vertex
        for(auto& edge : edges)
        {
            int src = edge.src;
            int dst = edge.dst;
            
            adjList[src].push_back(dst);
        }
    }
};

void DFS(Graph& graph, int v, vector<bool>& discovered, vector<int>& arrival, vector<int>& departure, int& time)
{
    // record arrival time
    arrival[v] = ++time;
    
    // mark as discovered the first time
    discovered[v] = true;

    for(int dst : graph.adjList[v])
    {
        if(!discovered[dst])
            DFS(graph, dst, discovered, arrival, departure, time);
    }

    // record departure time
    departure[v] = ++time;
}

int main()
{
    vector<Edge> edges = { {0, 1}, {0, 2}, {2, 3}, {2, 4}, {3, 1}, {3, 5}, {4, 5}, {6, 7} };
    
    Graph graph(edges);
    vector<int> arrival(edges.size());
    vector<int> departure(edges.size());
    vector<bool> discovered(edges.size());
    int time = -1;
    
    // as there could be un-connected subgraphs, scan the entire array
    for(size_t i = 0; i < discovered.size(); ++i)
        if(!discovered[i]) DFS(graph, i, discovered, arrival, departure, time);
        
    // print out results
    for(size_t i = 0; i < discovered.size(); ++i)
        cout << i << ", arrival: " << arrival[i] << ", departure: " << departure[i] << endl;
        
    return 0;
}