// https://www.techiedelight.com/print-all-hamiltonian-path-present-in-a-graph/

#include <iostream>
#include <vector>
using namespace std;
 
// Data structure to store a graph edge
struct Edge {
    int src, dest;
};
 
// A class to represent a graph object
class Graph
{
public:
    // a vector of vectors to represent an adjacency list
    vector<vector<int>> adjList;
 
    // Constructor
    Graph(vector<Edge> const &edges, int N)
    {
        // resize the vector to hold `N` elements of type `vector<int>`
        adjList.resize(N);
 
        // add edges to the undirected graph
        for (Edge edge: edges)
        {
            int src = edge.src;
            int dest = edge.dest;
 
            adjList[src].push_back(dest);
            adjList[dest].push_back(src);
        }
    }
};
 
// Utility function to print a path
void printPath(vector<int> const &path)
{
    for (int i: path) {
        cout << i << ' ';
    }
    cout << endl;
}
 
void printAllHamiltonianPaths(Graph const &g, int v, vector<bool>
                        visited, vector<int> &path, int N)
{
    // if all the vertices are visited, then the Hamiltonian path exists
    if (path.size() == N)
    {
        // print the Hamiltonian path
        printPath(path);
        return;
    }
 
    // Check if every edge starting from vertex `v` leads
    // to a solution or not
    for (int w: g.adjList[v])
    {
        // process only unvisited vertices as the Hamiltonian
        // path visit each vertex exactly once
        if (!visited[w])
        {
            visited[w] = true;
            path.push_back(w);
 
            // check if adding vertex `w` to the path leads
            // to the solution or not
            printAllHamiltonianPaths(g, w, visited, path, N);
 
            // backtrack
            visited[w] = false;
            path.pop_back();
        }
    }
}
 
int main()
{
    // consider a complete graph having 4 vertices
    vector<Edge> edges = {
        {0, 1}, {0, 2}, {0, 3}, {1, 2}, {1, 3}, {2, 3}
    };
 
    // starting node
    int start = 0;
 
    // total number of nodes in the graph
    int N = 4;
 
    // build a graph from the given edges
    Graph g(edges, N);
 
    // add starting node to the path
    vector<int> path;
    path.push_back(start);
 
    // mark the start node as visited
    vector<bool> visited(N);
    visited[start] = true;
 
    printAllHamiltonianPaths(g, start, visited, path, N);
 
    return 0;
}
