#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
using namespace std;
const int N = 105;

struct node{
	int u,w;
	bool operator<(const node &rhs)const{
		return w > rhs.w;
	}
};

int G[N][N];
int d[N][N][2];
int n,m;
void dijkstra(int s){
	priority_queue<node>pq;

	for(int i=0;i<n;i++){
		if(G[s][i])
			pq.push({i,G[s][i]});
	}

	while(!pq.empty()){
		auto item = pq.top();pq.pop();
		int cost = item.w;
		int u = item.u;
		
		if(d[s][u][0]==0){
			d[s][u][0] = cost;
		}else {
			if(cost < d[s][u][0]){
				d[s][u][1] = d[s][u][0];
				d[s][u][0] = cost;
			}else if(cost == d[s][u][0]){
				continue;
			}else if(d[s][u][1]==0 || d[s][u][1] > cost)
				d[s][u][1] = cost;
			else{
				continue;
			}
		}
		for(int i=0;i<n;i++)
			if(G[u][i])
				pq.push({i,G[u][i] + cost});
	}
}

int main(){
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int q,Case=0;
	int from,to,dist;
	while(cin>>n>>m){
		Case++;
		memset(G,0,sizeof(G));
		for(int i=0;i<m;i++){
			cin>>from>>to>>dist;
			G[from][to] = dist;
			G[to][from] = dist;
		}
		int q;
		memset(d,0,sizeof(d));
		cout<<"Set #"<<Case<<endl;
		cin>>q;
		for(int i=0;i<n;i++){
			dijkstra(i);
		}
		for(int i=0;i<q;i++){
			cin>>from>>to;
			if(from==to){
				if(d[from][to][0]){
					cout<<d[from][to][0]<<endl;
				}else
					cout<<'?'<<endl;
				//cout<<d[from][to][0]<<endl;
			}else{
				if(d[from][to][1])
					cout<<d[from][to][1]<<endl;
				else
					cout<<'?'<<endl;
			}
		}
	}
	return 0;
}
