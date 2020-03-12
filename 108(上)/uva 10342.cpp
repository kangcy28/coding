#include <bits/stdc++.h>
using namespace std;
int G[105][105],d[105][105][2],n;
struct node{
	int u,cost;

	bool operator<(const node &rhs)const{
		return cost > rhs.cost;
	}
};
void dijkstra(int s){
	priority_queue<node>pq;


	for(int i=0;i<n;i++){
		if(G[s][i])
			pq.push({i,G[s][i]});
	}
	while(!pq.empty()){
		node t = pq.top();pq.pop();
		
		int u = t.u,cost = t.cost;

		if(d[s][u][0]==0){//如果沒有最短
			d[s][u][0] = cost;
		}else{//如果有最短
			if(d[s][u][0] > cost){//最短比較大
				d[s][u][1] = d[s][u][0];
				d[s][u][0] = cost;
			}else if(d[s][u][0] == cost)continue;//與最短相等
			else if(d[s][u][1] == 0 ||cost < d[s][u][1])//次短為0或次短較大
				d[s][u][1] = cost;
			else continue;
		}
		//cout<<s<<' '<<u<<' '<<d[s][u][0]<<' '<<d[s][u][1]<<endl;
		for(int i=0;i<n;i++){
			if(G[u][i])
				pq.push({i,G[u][i]+cost});
		}
	}
}
int main(){
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int m,u,v,cnt=1;
	while(cin>>n>>m){
		memset(d,0,sizeof(d));
		memset(G,0,sizeof());
		cout<<"Set #"<<cnt<<endl;
		cnt++;
		for(int i=0;i<m;i++){
			cin>>u>>v>>G[u][v];
			G[v][u] = G[u][v];
		}
		for(int i=0;i<n;i++)
			dijkstra(i);
		int cas,a,b;
		cin>>cas;

		for(int i=1;i<=cas;i++){
			cin>>a>>b;
			if(a!=b){
				if(d[a][b][1])
					cout<<d[a][b][1]<<endl;
				else
					cout<<'?'<<endl;
			}else{
				if(d[a][b][0])
					cout<<d[a][b][0]<<endl;
				else
					cout<<'?'<<endl;
			}
		}
	}
	return 0;
}