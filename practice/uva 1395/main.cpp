#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n,m;
int p[10005];

struct edge{
    int from,to,w;
    edge(){};
    edge(int _from, int _to, int _w){
        from = _from;
        to = _to;
        w = _w;
    }
    bool operator<(const edge &rhs)const{
        return w < rhs.w;
    }
};
int Find(int x){
    if(p[x] == x)return x;
    return p[x] = Find(p[x]);
}
void init(){
    for(int i=0;i<10005;i++)
        p[i] = i;
}
vector<edge>v;
int kruskal(){
    int mx = 100000;

    for(int i=0;i<m;i++){
        init();
        int cnt = n-1;
        for(int j=i;j<m;j++){//枚舉邊
            int dx = Find(v[j].from);
            int dy = Find(v[j].to);

            if(dx != dy){//兩個點的p不同
                if(dx < dy){
                    p[dy] = dx;
                }else{
                    p[dx] = dy;
                }
                cnt--;
            }

            if(cnt==0){
                mx = min(mx,v[j].w - v[i].w);//最大邊減最小邊
                break;
            }
        }

    }
    return mx;
}
int main()
{
    //ios::sync_with_stdio(false);
    while(cin>>n>>m){
        if(n==0&&m==0)
            break;
        v.clear();
        int f,t,w;
        for(int i=0;i<m;i++){
            cin>>f>>t>>w;
            v.push_back(edge(f,t,w));
        }
        sort(v.begin(),v.end());
        int ans = kruskal();
        if(ans == 100000)
            cout<<"-1"<<endl;
        else
            cout<<ans<<endl;
    }
    return 0;
}
