#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
int cnt,num,server,from,to;
int p[1005],k;
vector<int>g[1005];
vector<int>node[1005];
bool c[1005];

void dfs(int u, int f, int dist){
    p[u] = f;

    int nd = g[u].size();

    if(nd==1&&dist>k){
        node[dist].push_back(u);
    }
    for(int i=0;i<nd;i++){
        int v = g[u][i];
        if(v!=f)dfs(v,u,dist+1);
    }
}
void dfs2(int v, int f, int dist){
    c[v] = true;
    int nd = g[v].size();

    for(int i=0;i<nd;i++){
        int u = g[v][i];
        if(u!=f&&dist<k)dfs2(u,v,dist+1);
    }
}
int solve(){
    int ans = 0;
    memset(c,false,sizeof(c));
    for(int dist = num-1;dist >k;dist--){
        for(int i=0;i<node[dist].size();i++){

            int u = node[dist][i];
            int v = u;
            if(c[v])
                continue;

            for(int j=0;j<k;j++)
                v = p[v];
            dfs2(v,-1,0);
            ans++;
        }
    }
    return ans;
}
int main()
{
    cin>>cnt;

    while(cnt--){
        cin>>num>>server>>k;
        for(int i=1;i<=num;i++){
            g[i].clear();
            node[i].clear();
        }
        for(int i=0;i<num-1;i++){
            cin>>from>>to;
            g[from].push_back(to);
            g[to].push_back(from);
        }
        dfs(server,-1,0);
        cout<<solve()<<endl;
    }
    return 0;
}
