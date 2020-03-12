#include<bits/stdc++.h>
const int N = 105,inf = 10000000;
using namespace std;
int n,s,t,edge,from,to,d[N],w;
bool vis[N];

struct Edge{
	int from,to,w;
};
struct node
{
	int u,w;
	bool operator<(const node &rhs)const{
		return w > rhs.w;
	}
};
vector<Edge>edges;
vector<int>G[N];

void addedge(int from,int to,int w){
	edges.push_back({from,to,w});
	int m = edges.size();
	G[from].push_back(m-1);
}

void dijkstra(){
	d[s] = 0;
	priority_queue<node,vector<node>,less<node>>q;

	q.push({s,0});
	while(!q.empty()){
		auto k = q.top();q.pop();
		int u = k.u, dis = k.w;

		vis[u] = true;
		for(auto it : G[u]){
			auto x = edges[it];
			int v = x.to,w = x.w;

			if(vis[v])continue;
			if(d[v] > d[u] + w){
				d[v] = d[u] + w;
				q.push({v,d[v]});
			}
		}
	}
}
int main(){
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int Case;
	int cnt=0;
	cin>>Case;
	while(Case--){
		if(cnt)cout<<endl;
		cnt++;

		edges.clear();
		for(int i=1;i<=N;i++)
			G[i].clear();
		cin>>n>>s>>t>>edge;

		for(int i=0;i<edge;i++){
			cin>>to>>from>>w;
			addedge(from,to,w);
		}

		for(int i=1;i<=N;i++){
			vis[i] = false;
			d[i] = inf;
		}

		dijkstra();

		int ans = 0;
		for(int i=1;i<=n;i++){
			//cout<<d[i]<<' ';
			if(d[i] <= t)
				ans++;
		}
		//cout<<endl;
		cout<<ans<<endl;
	}
	return 0;
}