// https://leetcode.com/problems/minimum-xor-sum-of-two-arrays/

// #define main dummy_main
// {}
// #undef main

// minCostFlow<int,ll>  mf;




// Number of vertices in given graph
#define V 6
 
/* Returns true if there is a path from source 's' to sink
  't' in residual graph. Also fills parent[] to store the
  path */
bool bfs(int rGraph[V][V], int s, int t, int parent[])
{
    // Create a visited array and mark all vertices as not
    // visited
    bool visited[V];
    memset(visited, 0, sizeof(visited));
 
    // Create a queue, enqueue source vertex and mark source
    // vertex as visited
    queue<int> q;
    q.push(s);
    visited[s] = true;
    parent[s] = -1;
 
    // Standard BFS Loop
    while (!q.empty()) {
        int u = q.front();
        q.pop();
 
        for (int v = 0; v < V; v++) {
            if (visited[v] == false && rGraph[u][v] > 0) {
                // If we find a connection to the sink node,
                // then there is no point in BFS anymore We
                // just have to set its parent and can return
                // true
                if (v == t) {
                    parent[v] = u;
                    return true;
                }
                q.push(v);
                parent[v] = u;
                visited[v] = true;
            }
        }
    }
 
    // We didn't reach sink in BFS starting from source, so
    // return false
    return false;
}
 
// Returns the maximum flow from s to t in the given graph
int fordFulkerson(int graph[V][V], int s, int t)
{
    int u, v;
 
    // Create a residual graph and fill the residual graph
    // with given capacities in the original graph as
    // residual capacities in residual graph
    int rGraph[V]
              [V]; // Residual graph where rGraph[i][j]
                   // indicates residual capacity of edge
                   // from i to j (if there is an edge. If
                   // rGraph[i][j] is 0, then there is not)
    for (u = 0; u < V; u++)
        for (v = 0; v < V; v++)
            rGraph[u][v] = graph[u][v];
 
    int parent[V]; // This array is filled by BFS and to
                   // store path
 
    int max_flow = 0; // There is no flow initially
 
    // Augment the flow while tere is path from source to
    // sink
    while (bfs(rGraph, s, t, parent)) {
        // Find minimum residual capacity of the edges along
        // the path filled by BFS. Or we can say find the
        // maximum flow through the path found.
        int path_flow = INT_MAX;
        for (v = t; v != s; v = parent[v]) {
            u = parent[v];
            path_flow = min(path_flow, rGraph[u][v]);
        }
 
        // update residual capacities of the edges and
        // reverse edges along the path
        for (v = t; v != s; v = parent[v]) {
            u = parent[v];
            rGraph[u][v] -= path_flow;
            rGraph[v][u] += path_flow;
        }
 
        // Add path flow to overall flow
        max_flow += path_flow;
    }
 
    // Return the overall flow
    return max_flow;
}



class MaxFlow {
    public:
        malloc();
        init();
        addEdge(int from, int to, );
        solve(int from, int to, );
};



class Solution {
public:
    int minimumXORSum(vector<int>& nums1, vector<int>& nums2) {
        // dummy_main();
        MaxFlow mf;
        mf.malloc(30);
        mf.init(30);
        int n = nums1.size();
        int m = nums2.size();
        int source = n+m, sink = source+1;
        rep(i, n){
            rep(j, m){
                int from = i, to = j + n;
                mf.addEdge(from, to, 1, nums1[i]^nums2[j]);
            }
        }
        rep(i, n) mf.addEdge(source, i, 1, 0);
        rep(i, m) mf.addEdge(i+n, sink, 1, 0);
        int flow, cost;
        mf.solve(source, sink, flow ,cost, -2, 4d9);
        return cost;
    }
};

