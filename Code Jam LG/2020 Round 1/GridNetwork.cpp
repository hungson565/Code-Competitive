// https://codejam.lge.com/problem/18769

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <algorithm>
#include <unordered_map>

using namespace std;

int64_t T;

/*

3
2 3
1 3
3 1
2 4 2
2 2
1
1
2 2
3 3
1 2
1 4
4 3
2 3 3
3 2 1

*/

// a structure to represent a weighted edge in graph
struct Edge {
    int64_t src, dest, weight;
};
 
// a structure to represent a connected, undirected
// and weighted graph
struct Graph {
    // V-> Number of vertices, E-> Number of edges
    int64_t V, E;
 
    // graph is represented as an array of edges.
    // Since the graph is undirected, the edge
    // from src to dest is also edge from dest
    // to src. Both are counted as 1 edge here.
    struct Edge* edge;
};
 
// Creates a graph with V vertices and E edges
struct Graph* createGraph(int64_t V, int64_t E)
{
    struct Graph* graph = (struct Graph*)(malloc(sizeof(struct Graph)));
    graph->V = V;
    graph->E = E;
 
    graph->edge = (struct Edge*)malloc(sizeof( struct Edge)*E);
 
    return graph;
}
 
// A structure to represent a subset for union-find
struct subset {
    int64_t parent;
    int64_t rank;
};
 
// A utility function to find set of an element i
// (uses path compression technique)
int64_t find(struct subset subsets[], int64_t i)
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
void Union(struct subset subsets[], int64_t x, int64_t y)
{
    int64_t xroot = find(subsets, x);
    int64_t yroot = find(subsets, y);
 
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
int64_t KruskalMST(struct Graph* graph)
{
    int64_t V = graph->V;
    struct Edge
        result[V]; // Tnis will store the resultant MST
    int64_t e = 0; // An index variable, used for result[]
    int64_t i = 0; // An index variable, used for sorted edges
 
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
    for (int64_t v = 0; v < V; ++v) {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }
 
    // Number of edges to be taken is equal to V-1
    while (e < V - 1 && i < graph->E) {
        // Step 2: Pick the smallest edge. And increment
        // the index for next iteration
        struct Edge next_edge = graph->edge[i++];
 
        int64_t x = find(subsets, next_edge.src);
        int64_t y = find(subsets, next_edge.dest);
 
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
    int64_t minimumCost = 0;
    for (i = 0; i < e; ++i)
    {
        // printf("%d -- %d == %d\n", result[i].src,
        //    result[i].dest, result[i].weight);
        minimumCost += (int64_t) result[i].weight;
    }
    // printf("Minimum Cost Spanning tree : %d",minimumCost);
    return minimumCost;
}


void solve() {
    int64_t R, C;
    cin >> R;
    cin >> C;
    vector<vector<int64_t>> cost_row(R, vector<int64_t>());
    vector<vector<int64_t>> cost_colum(R - 1, vector<int64_t>());
    int64_t val;
    for (int64_t i = 0; i < R; i++) {
        for (int64_t j = 0; j < C - 1; j++) {
            cin >> val;
            // scanf("%lld", &val);
            cost_row[i].push_back(val);
        }
        
    }
    for (int64_t i = 0; i < R - 1; i++) {
        for (int64_t j = 0; j < C; j++) {
            cin >> val;
            // scanf("%lld", &val);
            cost_colum[i].push_back(val);
        }
    }

    int64_t V = R * C; // Number of vertices in graph
    int64_t E = R * (C - 1) + (R - 1) * C ; // Number of edges in graph

    struct Graph* graph = createGraph(V, E);
    int64_t index = 0;
    for (int64_t i = 0; i < R; i++) {
        for (int64_t j = 0; j < C - 1; j++) {
            int s = (i) * C + j;
            int d = (i) * C + j + 1;
            graph->edge[index].src = s;
            graph->edge[index].dest = d;
            graph->edge[index].weight = (int64_t) cost_row[i][j];
            index++;
        }
    }

    for (int64_t i = 0; i < R - 1; i++) {
        for (int64_t j = 0; j < C; j++) {
            int d = (i) * C + j;
            int s = (i + 1) * C + j;
            graph->edge[index].src = s;
            graph->edge[index].dest = d;
            graph->edge[index].weight = (int64_t) cost_colum[i][j];
            index++;
        }
    }

    cout << KruskalMST(graph) << "\n";

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
    while (T > 0) {
        solve();
        T--;
    }
    return 0;
}
