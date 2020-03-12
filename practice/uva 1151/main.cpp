#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
using namespace std;

int n,q,cnt;
int p[10005],px[1005],py[1005],vis[1005];
const int inf = 1<<30;

struct node{
    int a,b;
    int w;
    bool operator<(const node &rhs)const{
        return w < rhs.w;
    }
}e[1005*1005/2],ex[1005];

int Find(int x){
    if(p[x] == x)return x;
    return p[x] = Find(p[x]);
}

struct net{
    int cnt;
    int point[1005];
    int w;
}c[10];

int kruskal(int r){
    int ans=0;

    for(int i=0;i<n;i++) p[i]=i;
    memset(vis,0,sizeof(vis));
    for(int i=0;i<q;i++){
        if((r>>i)&&1){
            ans += c[i].w;
            int k = c[i].point[0];
            for(int j=0;j<c[i].cnt;j++){
                if(vis[c[i].point[j]]){
                    k = Find(c[i].point[j]);
                    break;
                }
            }
            for(int j=0;j<c[i].cnt;j++){
                if(!vis[c[i].point[j]]) p[c[i].point[j]] = k;
                vis[c[i].point[j]]=1;
            }
        }
    }
    for(int i=0;i<n-1;i++){
        int x = Find(ex[i].a), y = Find(ex[i].b);
        if(x!=y){
            ans += ex[i].w;
            p[y] = x;
        }
    }
    return ans;
}

int solve(){
    int ans = inf;
    int c2 = 0;

    sort(e,e+cnt);
    for(int i=0;i<n;i++)
        p[i] = i;

    for(int i=0;i<cnt;i++){
        int x = Find(e[i].a),y = Find(e[i].b);
        if(x!=y){
            p[y] = x;
            ex[c2++]=e[i];
        }
    }

    for(int i=0;i<(1<<q);i++){
        ans = min(ans,kruskal(i));
    }

    return ans;
}
int main()
{
    int cases;
    int kase = 0;

    cin>>cases;
    while(cases--){
        if(kase++)cout<<endl;

        cin>>n>>q;
        for(int i=0;i<q;i++){
            cin>>c[i].cnt>>c[i].w;
            for(int j=0;j<c[i].cnt;j++){
                cin>>c[i].point[j];
                c[i].point[j]--;
            }
        }
        for(int i=0;i<n;i++)
            cin>>px[i]>>py[i];
        cnt = 0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                e[cnt].a = i; e[cnt].b = j;
                e[cnt++].w = (px[i]-px[j])*(px[i]-px[j])+(py[i]-py[j])*(py[i]-py[j]);
            }
        }
        cout<<solve()<<endl;
    }
    return 0;
}
