#include <bits/stdc++.h>
using namespace std;
struct city{
	int x,y,p;
};
struct edge{
	int from,to,dis;
	bool operator<(const edge &rhs)const{
		return dis < rhs.dis;
	}
};
int dis(city a, city b){
	return (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y);
}
vector<city>citys;
vector<edge>edges,G[1005];
int p[1005],D[1005][1005];

int Find(int n){
	if(p[n] == n)
		return n;
	return p[n] = Find(p[n]);
}
void Union(int a, int b){
	if(p[a] != p[b])
		p[Find(p[a])] = Find(p[b]);
}

void dfs(int u, int f, double dis, int *d){
	d[u] = dis;
	for(int i=0;i<G[u].size();i++){
		int v = G[u][i].to;
		double cost = G[u][i].dis;
		if(v==f)continue;
		dfs(v, u, max(dis,cost),d);
	}
}
int main(){
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int Case,x,y,po,n;

	cin>>Case;
	while(Case--){
		for(int i=0;i<1005;i++){
			G[i].clear();
			p[i] = i;
		}
		memset(D,0,sizeof(D));
		citys.clear();
		edges.clear();
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>x>>y>>po;
			citys.push_back((city){x,y,po});
		}
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				edges.push_back((edge){i, j, dis(citys[i],citys[j])});
			}
		}
		int m = 0, road=0;

		sort(edges.begin(),edges.end());
			
		for(int i=0;i<edges.size();i++){
			int a = edges[i].from;
			int b = edges[i].to;
			int dis = edges[i].dis;

			if(p[a]!=p[b]){
				Union(a,b);
				m++;
				G[a].push_back((edge){a,b,dis});
				G[b].push_back((edge){b,a,dis});
				road += dis;
			}
			if(m==n-1)break;
		}
		double ans = 0;
		for(int i=0;i<n;i++)
			dfs(i,-1,0,D[i]);
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				ans = max(ans,(citys[i].p + citys[j].p) * 1.0/(road - D[i][j]));
			}
		}
		printf("%.2f\n",(double)ans);
	}
	return 0;
}