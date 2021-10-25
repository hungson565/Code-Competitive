// https://leetcode.com/problems/minimum-cost-to-make-at-least-one-valid-path-in-a-grid/
// https://leetcode.com/problems/minimum-cost-to-make-at-least-one-valid-path-in-a-grid/discuss/525188/min-cost-flow-algorithm-spfa-c

class Solution {
public:
    int m,n;
    int S,T;
    int dir[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
    int head[30000];
    struct Edge{
        int to;
        int next;
        int remain;
        int fi;
    }e[300000];
    int en;
    
    void add(int from, int to, int flow, int fi){
        addEdge(from,to,flow,fi);
        addEdge(to,from,0,-fi);
    }
    
    void addEdge(int from, int to, int flow, int fi){
        e[en].next=head[from];
        e[en].to=to;
        e[en].remain=flow;
        e[en].fi=fi;
        head[from]=en;
        ++en;
    }
    
    int minCost(vector<vector<int>>& grid) {
        en=0;
        memset(head,-1,sizeof(head));
        m=grid.size();
        n=grid[0].size();
        S=2*m*n;
        T=2*m*n+1;
        
        add(S,0,1,0);
        add(2*m*n-1,T,1,0);
        for(int i=0;i<m*n;i++){
            add(i,i+m*n,1,0);
            int x=i/n;
            int y=i%n;
            for(int d=0;d<4;d++){
                int nx=x+dir[d][0];
                int ny=y+dir[d][1];
                if(nx<0 || nx>=m || ny<0 || ny>=n) continue;
                if(d+1!=grid[x][y]){      
                    add(i+m*n,nx*n+ny,1,1);
                }else{
                    add(i+m*n,nx*n+ny,1,0);
                }
            }
        }
        return EK();
    }
    
    int EK(){
        int res=0;
        
        while(true){
            vector<int> dis(2*m*n+2,INT_MAX);
            vector<int> pre(2*m*n+2,-1);
            spfa(pre,dis);
            if(pre[T]==-1) break;
            int v=T;
            while(true){
                int edge=pre[v];
                e[edge].remain--;
                e[edge^1].remain++;
                v=e[edge^1].to;
                if(v==S) break;
            }
            
            res+=dis[T];
        }
        return res;
    }
    
    void spfa(vector<int> &pre, vector<int> &dis){
        queue<int> q;
        vector<int> iq(2*m*n+2,0);
        
        q.push(S);
        iq[S]=1;
        dis[S]=0;
        while(!q.empty()){
            int cur=q.front();
            q.pop();
            iq[cur]=0;
            
            for(int i=head[cur];i!=-1;i=e[i].next){
                int v=e[i].to;
                
                if(e[i].remain>0 && dis[v]>dis[cur]+e[i].fi){
                    dis[v]=dis[cur]+e[i].fi;
                    pre[v]=i;
                    if(iq[v]==0){
                        iq[v]=1;
                        q.push(v);
                    }
                }
            }
        }
    }
};
