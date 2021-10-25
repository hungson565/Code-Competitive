// https://codejam.lge.com/problem/19596

// build: g++ -o GiftExchange GiftExchange.cpp -std=c++11 && GiftExchange

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
using namespace std;

int T;

#define NN 1001

/*


TC:

5
3 2
2 1
3 1
3 3
1 2
2 3
1 3
4 4
1 2
1 3
2 3
2 4
4 5
2 1
1 3
2 3
2 4
4 1
6 3
1 2
3 4
5 6






1
10 5
1 2
2 3
5 6
7 8
9 10

1
10 6
2 1
3 2
4 5
5 6
7 8
9 10


*/

class Graph{
    
    int vertex; // number of vertices
    // adjacency list
    // we are using unordered_map to speed up the deletion of edges
    vector<unordered_map<int,int>> adj;
    
    public:
        
        // constructor to initialize graph
        // set number of vertices to v
        // initialize adjacency map for v nodes
        Graph(int v){
            vertex = v;
            adj = vector<unordered_map<int,int>>(v+1);
        }
        
        // add edge (u, v) to graph
        void addEdge(int u, int v){
            adj[u][v] = 1;
            adj[v][u] = 1;
        }
        
        // remove edge (u, v) from the graph
        void removeEdge(int v,int u){
            adj[v].erase(u);
            adj[u].erase(v);
        }
        
        // function checks if the graph contains a euler path/circuit or not
        // if the graph is valid, then it calls another function printEuler()
        // to print Euler Path or circuit
        vector<int> printEulerPathCircuit(){
            vector<int> ans;
            int odd = 0; // number of vertices with odd degree
            int oddVertex = 0; // it stores vertex with odd degree if it exists
            
            for(int i=1;i<=vertex;++i){
                if(adj[i].size()%2==1){
                    ++odd;
                    oddVertex = i;
                }
            }
            
            if(odd==0){
                // if the number of odd degree vertices is 0
                // the graph contains a Euler Circuit
                // we can use any vertex as the starting vertex
                // cout<<"Euler Circuit: ";
                // print euler circuit with '1' as the starting vertex
                printEuler(1, ans);
            }
            else if(odd==2){
                // if the number of odd degree vertices is 0
                // the graph contains a Euler Path
                // starting vertex should be of odd degree
                // cout<<"Euler Path: ";
                printEuler(oddVertex, ans);
            }
            else{
                // cout<<"Euler Path/Circuit Doesn't Exist"<<endl;
            }
            return ans;
            
        }
        
        // the function to print euler path or circuit
        void printEuler(int v, vector<int>& ans){
            
            stack<int> cpath;    // current path
            stack<int> epath;    // euler path
            
            cpath.push(v);        // euler path starts from v
            
            while(!cpath.empty()){
                int u = cpath.top();
                
                if(adj[u].size()==0){
                    // if all edges from u are visited
                    // pop u and push it to euler path    
                    epath.push(u);
                    cpath.pop();
                }
                else{
                    // if all edges from u are not visited
                    // select any edge (u, v)
                    // push v to current path and remove edge (u, v) from the graph
                    cpath.push(adj[u].begin()->first);
                    removeEdge(u,adj[u].begin()->first);
                }    
            }
            
            while(!epath.empty()){
                // cout<<" "<<epath.top()<<" ";
                ans.push_back(epath.top());
                epath.pop();
            }
            
        }
        
};

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

void cal() {
    int N;
    int M;
    cin >> N;
    cin >> M;

    init();
    vector<pair<int, int>> adj;

    int v1;
    int v2;

    for (int i = 0; i < M; i++) {
        cin >> v1;
        cin >> v2;
        join(v1, v2);
        adj.push_back({v1, v2});
    }

    vector<Graph> Gs;
    unordered_map<int, int> map_v_to_G;
    int index_G = 0;
    for (int i = 1; i <= N; i++) {
        auto p = find(i);
        if (!map_v_to_G.count(p)) {
            // cout << "i: " << i << ", p: " << p << ", index: " << index_G << endl;
            Graph g(NN);
            Gs.push_back(g);
            map_v_to_G[p] = index_G;
            index_G++;
        }
    }

    // cout << "Gs.size(): " << Gs.size() << endl;

    for (int i = 0; i < M; i++) {
        int v1 = adj[i].first;
        int v2 = adj[i].second;
        auto p = find(v1);
        auto index_G = map_v_to_G[p];
        Gs[index_G].addEdge(v1, v2);
    }

    set<pair<int, int>> m;

    for (auto G : Gs) {
        auto ans = G.printEulerPathCircuit();
        // for (auto e : ans ) {
        //     cout << e << " ";
        // }
        // cout << endl;
        int size = ans.size();
        for (int i = 0; i < size - 1; i++) {
            m.insert({ans[i], ans[i + 1]});
        }
    }


    string s;
    for (auto e : adj) {
        if (m.find(e) != m.end()) {
            s += '1';
        } else {
            s += '0';
        }
    }
    cout << s << endl;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
    while (T > 0) {
        cal();
        T--;
    }
}
