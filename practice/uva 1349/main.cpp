#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
const int maxn = 100 + 23<<2;
const int inf = 1e6;
struct Edge{
    int from, to, cap, flow, cost;
};

struct MCMF{
    int n, m, s, t;
    vector<Edge>edges;
    vector<int>G[maxn];

    int inq[maxn];
    int d[maxn];
    int p[maxn];
    int a[maxn];

    void init(int n){
        this->n = n;
        for(int i=0;i<n;i++){
            G[i].clear();
        }
        edges.clear();
    }

    void AddEdge(int from, int to, int cap, int cost){
        edges.push_back((Edge){from, to, cap, 0, cost});
        edges.push_back((Edge){to, from, 0, 0, -cost});
        m = edges.size();
        G[from].push_back(m-2);
        G[to].push_back(m-1);
    }
    bool BellmanFord(int s, int t, int &flow, int cost){
        for(int i=0;i<n;i++) d[i] = inf;
        memset(inq, 0, sizeof(inq));
        d[s] = 0;inq[s] = 1;p[s] = 0;a[s] = inf;
        queue<int>q;
        q.push(s);
        while(!q.empty()){
            int u = q.front();q.pop();
            inq[u] = 0;
            for(int i=0;i<G[u].size();i++){
                Edge &e = edges[G[u][i]];
                if(e.cap > e.flow && d[e.to] > d[u] + e.cost){
                    d[e.to] = d[u] + e.cost;
                    p[e.to] = G[u][i];
                    a[e.to] = min(a[u], e.cap - e.flow);
                    if(!inq[e.to]){
                        q.push(e.to);
                        inq[e.to] = 1;
                    }
                }
            }
        }
        if(d[t] == inf)return false;
        flow += a[t];
        cost += d[t] * a[t];
        int u = t;
        while(u != s){
            edges[p[u]].flow += a[t];
            edges[p[u]^1].flow -= a[t];
            u = edges[p[u]].from;
        }
        return true;
    }
    int Mincost(int s, int t, int&flow){
        int cost = 0;
        flow = 0;
        while(BellmanFord(s,t,flow,cost));
        return cost;
    }
}mm;
int main()
{
    int n,u,v;
    cin>>n;
    while(cin>>n){
        if(!n)break;
        mm.init(2*n+10);
        for(int i=1;i<=n;i++){
            mm.AddEdge(0,u,1,0);
            mm.AddEdge(i+n,2*n+1,1,0);
            int u,v;
            while(1){
                cin>>u;
                if(u==0)break;
                cin>>v;
                mm.AddEdge(i,u+n,1,v);

            }
        }
        int flow;
        int ans = mm.Mincost(0,2*n+1,flow);
        if(flow==n)cout<<ans<<endl;
        else{
            cout<<"N"<<endl;
        }
    }
    return 0;
}
