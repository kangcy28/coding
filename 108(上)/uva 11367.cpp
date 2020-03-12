#include <bits/stdc++.h>
using namespace std;
const int maxn = 1005;
const int inf = 0x3f3f3f3f;
struct State{
	int u,l,d;// 點 現在多少油 花費
	bool operator<(const State &rhs)const{
		return d > rhs.d;
	}
};
vector<int>p;
vector<pair<int,int>>G[maxn];

int d[maxn][maxn];
bool vis[maxn][maxn];
void Addedge(int from, int to, int dist){
	G[from].push_back({to,dist});
	G[to].push_back({from,dist});
}
int dijkstra(int s,int e,int c){
	memset(d,inf,sizeof(d));
	memset(vis,0,sizeof(vis));

	d[s][0] = 0;
	priority_queue<State>q;

	q.push({s,0,d[s][0]});

	while(!q.empty()){
		auto x = q.top();q.pop();
		int u = x.u, l = x.l;
		//cout<<u<<' '<<l<<endl;
		if(vis[u][l])continue;
		vis[u][l] = true;

		for(int i=0;i<G[u].size();i++){
			int v = G[u][i].first, w = G[u][i].second;

			if(w > l)continue;
			if(d[v][l-w] > d[u][l]){//u->v 的cost較小比原本小
				d[v][l-w] = d[u][l];
				q.push({v,l-w,d[v][l-w]});
			} 
		}

		if(l < c && d[u][l+1] > d[u][l] + p[u]){//沒裝滿且在此地加比原本便宜
			d[u][l+1] = d[u][l] + p[u];
			q.push({u,l+1,d[u][l+1]});
		}
	}
	return d[e][0];
}
int main(){
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	
	int n,m,tmp,from,to,dis,Case,s,e,c;
	while(cin>>n>>m){
		for(int i=0;i<maxn;i++)
			G[i].clear();
		p.clear();
		for(int i=0;i<n;i++){
			cin>>tmp;
			p.push_back(tmp);
		}
		for(int i=0;i<m;i++){
			cin>>from>>to>>dis;
			Addedge(from,to,dis);
		}
		cin>>Case;

		while(Case--){
			
			cin>>c>>s>>e;
			int ans = dijkstra(s,e,c);
			if(ans == inf){
				cout<<"impossible"<<endl;
			}else{
				cout<<ans<<endl;
			}
		}
	}
	return 0;
}

/*有剩更多油時可以更新

油箱還有空位且在此地加一單位的油比較便宜*/