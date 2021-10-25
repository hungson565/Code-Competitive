// https://codejam.lge.com/problem/16202

// build: g++ -o MinimumSpanningTreeGame MinimumSpanningTreeGame.cpp -std=c++11 && MinimumSpanningTreeGame

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <algorithm>
#include <unordered_map>
using namespace std;

/*

6 6 2
1 2
2 3
1 3
4 5
5 6
4 6

*/

#define NN 1005

int parent[NN], r[NN], c[NN];

void init() {
    for (int i=0; i<NN; i++) {
        parent[i] = i;
        r[i] = 0;
        c[i] = 1;
    }
}

void erase() {
    for (int i=0; i<NN; i++) {
        parent[i] = 0;
        r[i] = 0;
        c[i] = 0;
    }
}

int find(int u) {
    if (parent[u] != u) parent[u] = find(parent[u]);
    return parent[u];
}

void join(int u, int v) {
    u = find(u);
    v = find(v);
    if (u == v) return;
    if (r[u] == r[v]) {
        r[u]++;
    }
    if (r[u] < r[v]) {
        parent[u] = v;
        c[v]++;
    }
    else {
        parent[v] = u;
        c[u]++;
    }
}

//-------------------------------------------------------------------------

// a structure to represent a weighted edge in graph
struct Edge {
    int src, dest, weight;
};
 
// a structure to represent a connected, undirected
// and weighted graph
struct Graph {
    // V-> Number of vertices, E-> Number of edges
    int V, E;
 
    // graph is represented as an array of edges.
    // Since the graph is undirected, the edge
    // from src to dest is also edge from dest
    // to src. Both are counted as 1 edge here.
    struct Edge* edge;
};
 
// Creates a graph with V vertices and E edges
struct Graph* createGraph(int V, int E)
{
    struct Graph* graph = (struct Graph*)(malloc(sizeof(struct Graph)));
    graph->V = V;
    graph->E = E;
 
    graph->edge = (struct Edge*)malloc(sizeof( struct Edge)*E);
 
    return graph;
}
 
// A structure to represent a subset for union-find
struct subset {
    int parent;
    int rank;
};
 
// A utility function to find set of an element i
// (uses path compression technique)
int find(struct subset subsets[], int i)
{
    // find root and make root as parent of i
    // (path compression)
    if (subsets[i].parent != i)
        subsets[i].parent
            = find(subsets, subsets[i].parent);
 
    return subsets[i].parent;
}
 
// A function that does union of two sets of x and y
// (uses union by rank)
void Union(struct subset subsets[], int x, int y)
{
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);
 
    // Attach smaller rank tree under root of high
    // rank tree (Union by Rank)
    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;
 
    // If ranks are same, then make one as root and
    // increment its rank by one
    else
    {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}
 
// Compare two edges according to their weights.
// Used in qsort() for sorting an array of edges
int myComp(const void* a, const void* b)
{
    struct Edge* a1 = (struct Edge*)a;
    struct Edge* b1 = (struct Edge*)b;
    return a1->weight > b1->weight;
}
 
// The main function to construct MST using Kruskal's
// algorithm
int KruskalMST(struct Graph* graph)
{
    int V = graph->V;
    struct Edge
        result[V]; // Tnis will store the resultant MST
    int e = 0; // An index variable, used for result[]
    int i = 0; // An index variable, used for sorted edges
 
    // Step 1: Sort all the edges in non-decreasing
    // order of their weight. If we are not allowed to
    // change the given graph, we can create a copy of
    // array of edges
    qsort(graph->edge, graph->E, sizeof(graph->edge[0]),
        myComp);
 
    // Allocate memory for creating V ssubsets
    struct subset* subsets
        = (struct subset*)malloc(V * sizeof(struct subset));
 
    // Create V subsets with single elements
    for (int v = 0; v < V; ++v) {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }
 
    // Number of edges to be taken is equal to V-1
    while (e < V - 1 && i < graph->E) {
        // Step 2: Pick the smallest edge. And increment
        // the index for next iteration
        struct Edge next_edge = graph->edge[i++];
 
        int x = find(subsets, next_edge.src);
        int y = find(subsets, next_edge.dest);
 
        // If including this edge does't cause cycle,
        // include it in result and increment the index
        // of result for next edge
        if (x != y) {
            result[e++] = next_edge;
            Union(subsets, x, y);
        }
        // Else discard the next_edge
    }
 
    // print the contents of result[] to display the
    // built MST
    // printf(
    //     "Following are the edges in the constructed MST\n");
    int minimumCost = 0;
    for (i = 0; i < e; ++i)
    {
        // printf("%d -- %d == %d\n", result[i].src,
//            result[i].dest, result[i].weight);
        minimumCost += result[i].weight;
    }
    // printf("Minimum Cost Spanning tree : %d",minimumCost);
    return minimumCost;
}

//-------------------------------------------------------------------------

void solve() {
	int N;
    int M;
    int k;
    vector<pair<int, int>> adj;

    cin >> N;
    cin >> M;
    cin >> k;
    int v1, v2;
    for (int i = 0; i < M; i++) {
        cin >> v1;
        cin >> v2;
        adj.push_back({v1, v2});
        // cout << "push..." << i << endl;
    }

    // find Bound <= M is max value that edges from Bound to M - 1 makes CONNECTED
    int Bound = -1; // bound
    init();
    for (int i = M - 1; i >= 0; i--) {
        join(adj[i].first, adj[i].second);
        bool connected = true;
        auto value = find(1);
        for (int j = 1; j <= N; j++) {
            if (find(j) != value) {
                connected = false;
                break;
            }
        }
        if (connected == true) {
            Bound = i;
            break;
        }
    }

    for (int i = 0; i < k; i++) {
        if (i > Bound) {
            cout << "0 ";
            continue;
        } else {
            // cout << "Process i " << i << endl;;
            int V = 1010; // Number of vertices in graph
            int E = M - i; // Number of edges in graph
            struct Graph* graph = createGraph(V, E);
            int index = 0;
            for (int j = i; j < M; j++) {
                // add edge 0-1
                graph->edge[index].src = adj[j].first;;
                graph->edge[index].dest = adj[j].second;;
                graph->edge[index].weight = j + 1;
                index++;
            }

            cout << KruskalMST(graph) << " ";
        }

        

    }


}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
