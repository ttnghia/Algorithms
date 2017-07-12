#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

struct Edge { int src, dst; };
struct Graph
{
    int numVertices;
    vector<vector<int> > adj; 
    
    Graph(int numVertices_, const vector<Edge>& edges)
    {
        numVertices = numVertices_;
        adj.resize(numVertices_);
        
        for(auto& edge : edges)
            adj[edge.src].push_back(edge.dst);
    }
};

bool DFS(const Graph& graph, int v, vector<bool>& visited, vector<bool>& inStack)
{
    if(!visited[v])
    {
        visited[v] = true;
        inStack[v] = true;
        
        for(int u : graph.adj[v])
            if(!visited[u] && DFS(graph, u, visited, inStack)) return true;
            else if(inStack[u]) return true;
     }
      
     inStack[v] = false;
    
    return false;
}
        

bool detectCycle(const Graph& graph)
{
    vector<bool> visited(graph.numVertices);
    vector<bool> inStack(graph.numVertices);
    
    for(int v = 0; v < graph.numVertices; ++v)
        if(DFS(graph, v, visited, inStack))
           return true;
           
    return false;
}

int main()
{
    vector<Edge> edges;
    edges.push_back({ 0, 1 });
    edges.push_back({ 2, 0 });
    edges.push_back({ 1, 3 });
    edges.push_back({ 3, 2 });
    edges.push_back({ 2, 4 });
    edges.push_back({ 3, 5 });
    
    Graph graph(6, edges);
    
    if(detectCycle(graph))
       cout << "Graph has cycle!" << endl;
    else
       cout << "No cycle detected!" << endl;
    
    return 0;    
    
    return 0;
}
   