#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;
struct node{
    double w,t,c;
    int index;

    bool operator < (const node &rhs)const{
        return w < rhs.w;
    }
}nodes[1001];
vector<int>g[1001];
int parent[1001];
bool vis[1001];
int main()
{
    int n,m,from,to;

    while(cin>>n>>m){
        if(n==0&&m==0)
            break;
        queue<node> q;
        memset(parent,0,sizeof(parent));
        memset(vis,false,sizeof(vis));
        for(int i=1;i<=n;i++){
            cin>>nodes[i].w;
            nodes[i].t = 1;
            nodes[i].c = nodes[i].w;
            nodes[i].index = i;
            q.push(nodes[i]);
        }
        for(int i=0;i<n;i++){
            cin>>from>>to;
            parent[to] = from;
        }
        int ans=0;
        while(q.size()!=1){
            node k = q.front();q.pop();
            if(!vis[k.index]){
                vis[k.index] = true;
                int p = parent[k.index];
                ans += nodes[p].t * k.c;
                nodes[p].t += k.t;
                nodes[p].w = (k.c+nodes[p].c)/(k.t+nodes[p].t);
                q.push(nodes[p]);
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
