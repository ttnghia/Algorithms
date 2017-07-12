#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct Node { int parent, rank; };
struct Edge { int src, dst; };
struct Graph
{
    int numVertices;
    vector<Edge> edges;
    
    Graph(int numVertices_, const vector<Edge>& edges_)
    {
        numVertices = numVertices_;
        edges = edges_;
    }
};

int findRoot(vector<Node>& nodes, int i)
{
    if(nodes[i].parent != i)
        nodes[i].parent = findRoot(nodes, nodes[i].parent);
    
    return nodes[i].parent;
}

void unionSet(vector<Node>& nodes, int x, int y)
{
    int xroot = findRoot(nodes, x);
    int yroot = findRoot(nodes, y);
    
    if(nodes[xroot].rank < nodes[yroot].rank)
        nodes[xroot].parent = yroot;
    else
    {
        nodes[yroot].parent = xroot;
        
        if(nodes[xroot].rank == nodes[yroot].rank)
            nodes[xroot].rank++;
    }
}

bool detectCycle(const Graph& graph)
{
    vector<Node> nodes(graph.numVertices);
    
    for(int i = 0; i < graph.numVertices; ++i)
    {
        nodes[i].parent = i;
        nodes[i].rank = 0;
    }
    
    for(auto& edge : graph.edges)
    {
        int xroot = findRoot(nodes, edge.src);
        int yroot = findRoot(nodes, edge.dst);
        
        if(xroot == yroot) 
            return true;
        
        unionSet(nodes, xroot, yroot);
    }
    
    return false;
}

int main()
{
    vector<Edge> edges;
    edges.push_back({ 0, 1 });
    edges.push_back({ 0, 2 });
    edges.push_back({ 1, 3 });
    edges.push_back({ 2, 3 });
    edges.push_back({ 2, 4 });
    edges.push_back({ 3, 5 });
    
    Graph graph(6, edges);
    
    if(detectCycle(graph))
       cout << "Graph has cycle!" << endl;
    else
       cout << "No cycle detected!" << endl;
    
    return 0;   
}
    