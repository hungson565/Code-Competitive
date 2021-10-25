#include<iostream>
#include<vector>
#include<stack>
#include<unordered_map>
using namespace std;
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
        void printEulerPathCircuit(){
            
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
                cout<<"Euler Circuit: ";
                // print euler circuit with '1' as the starting vertex
                printEuler(1);
            }
            else if(odd==2){
                // if the number of odd degree vertices is 0
                // the graph contains a Euler Path
                // starting vertex should be of odd degree
                cout<<"Euler Path: ";
                printEuler(oddVertex);
            }
            else{
                cout<<"Euler Path/Circuit Doesn't Exist"<<endl;
            }
            
        }
        
        // the function to print euler path or circuit
        void printEuler(int v){
            
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
                cout<<" "<<epath.top()<<" ";
                epath.pop();
            }
            
        }
        
};
int main()
{
    // graph G, containing 6 vertices from 1 to 6.
    Graph G(6);
    
    // adding edges to the graph
    // this graph is same as the graph we used in the above example
    // we are assuming graph is connected and undirected
    G.addEdge(1, 6);
    G.addEdge(6, 3);
    G.addEdge(3, 2);
    G.addEdge(2, 1);
    G.addEdge(2, 5);
    G.addEdge(5, 4);
    G.addEdge(4, 2);
    
    // function to print Euler Path or Euler Circuit
    G.printEulerPathCircuit();
}
