#include <bits/stdc++.h>
using namespace std;
const int N = 50010;
struct edge{
	int from,to,dist;
	bool operator<(const edge &rhs)const{
		return dist < rhs.dist;
	}
};
vector<edge>edges;
vector<pair<int,int>>G[N];
int p[N];
int Find(int n){
	if(p[n] != n)
		return p[n] = Find(p[n]);
	return n;
}

void Union(int a,int b){
	if(p[a] != p[b])
		p[Find(p[a])] = Find(p[b]);
}
int ans = 1000000000;
bool vis[N];

void dfs(int u, int end, int Max){
	vis[u] = true;
	if(u == end){
		ans = min(ans, Max);
		return;
	}
	for(int i=0;i<G[u].size();i++){
		int v = G[u][i].first, cost = G[u][i].second;
		if(vis[v])continue;
		dfs(v,end,max(cost,Max));
	}
}
int main(){
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int n,m,from,to,dist,k=0;

	while(cin>>n>>m){
		if(k!=0)cout<<endl;
		k++;
		edges.clear();
		for(int i=0;i<N;i++){
			p[i] = i;
			G[i].clear();
		}
		for(int i=0;i<m;i++){
			cin>>from>>to>>dist;
			edges.push_back({from,to,dist});
		}
		sort(edges.begin(),edges.end());
		int cnt=0;
		for(int i=0;i<m;i++){
			int a = edges[i].from;
			int b = edges[i].to;
			int dist = edges[i].dist;
			if(Find(a) != Find(b)){
				Union(a,b);
				G[a].push_back({b,dist});
				G[b].push_back({a,dist});
				cnt++;
				if(cnt == n-1)
					break;
			}
		}

		int query;
		
		cin>>query;
		for(int i=0;i<query;i++){
			for(int j=0;j<N;j++)
				vis[j] = false;
			cin>>from>>to;
			ans = 1000000000;
			dfs(from,to,0);
			cout<<ans<<endl;
		}
	}
	return 0;
}