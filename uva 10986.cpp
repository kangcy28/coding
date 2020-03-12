#include<bits/stdc++.h>
#define inf 100000000
using namespace std;

struct edge{
	int from,to,w;
};
struct P{
	int node,dist;
	P(int _node,int _dist){
		node = _node;
		dist = _dist;
	}
	bool operator<(const P& rhs)const{
		return dist > rhs.dist;
	}
};
vector<edge>edges;
vector<int>G[20001];
int d[20001],Case,n,m,s,e,from,to,w,cnt;

void addedge(int from,int to, int w){
	edges.push_back({from,to,w});
	edges.push_back({to,from,w});
	int m = edges.size();
	G[from].push_back(m-2);
	G[to].push_back(m-1);
}
bool vis[20001];

void dijkstra(){
	priority_queue<P>q;
	d[s] = 0;
	q.push(P(s,d[s]));
	while(!q.empty()){
		auto x = q.top();q.pop();

		if(x.node == e)break;
		if(vis[x.node])continue;
		vis[x.node] = true;
		for(auto it:G[x.node]){
			auto node = edges[it];

			if(d[node.to] > d[node.from] + node.w){
				d[node.to] = d[node.from] + node.w;
				q.push({node.to,d[node.to]});
			}
		}
	}
}
void init(){
	edges.clear();
	for(int i=0;i<20001;i++){
		G[i].clear();
		d[i] = inf;
		vis[i] = false;
	}
	d[s] = 0;
}
int main(){
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	
	cin>>Case;
	while(Case--){
		
		cin>>n>>end>>c>>m;
		init();
		for(int i=0;i<m;i++){
			cin>>from>>to>>w;
			addedge(from,to,w);
		}
		dijkstra();
		cout<<"Case #"<<++cnt<<": ";
		if(d[e]==inf)
			cout<<"unreachable"<<endl;
		else
			cout<<d[e]<<endl;
	}
	return 0;
}