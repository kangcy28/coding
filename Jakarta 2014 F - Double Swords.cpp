#include<bits/stdc++.h>
using namespace std;
const int maxn = 1000005;
int cas = 0;
int a[maxn],b[maxn],c[maxn];
int d[maxn];
int lowbit(int x){
    return x&(-x);
}
void update(int x,int v){
    for(int i=x;i<maxn;i+=lowbit(i))
        d[i]+=v;
}
int get(int x){
    int ans = 0;
    for(int i=x;i;i-=lowbit(i))
        ans+=d[i];
    return ans;
}
void solve(){
    memset(d,0,sizeof(d));
    int n;scanf("%d",&n);
    vector<pair<pair<int,int>,int> >V;
    int ans = 0;
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d%d",&a[i],&b[i],&c[i]);
        a[i]++,b[i]++,c[i]++;
        if(get(a[i])-get(a[i]-1)==0)
            update(a[i],1);
        V.push_back(make_pair(make_pair(c[i],b[i]),a[i]));
    }
    sort(V.begin(),V.end());
    for(int i=0;i<V.size();i++){
        int tmp = get(V[i].first.first)-get(V[i].first.second-1);
        if(tmp==0)
            update(V[i].first.first,1);
        else if(tmp==1&&V[i].first.first>=V[i].second&&V[i].first.second<=V[i].second)
            update(V[i].first.first,1);
    }
    printf("Case #%d: %d\n",++cas,get(maxn-1));
}
int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int t;
    scanf("%d",&t);
    while(t--)solve();
    return 0;
}