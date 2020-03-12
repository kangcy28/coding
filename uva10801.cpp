#include<iostream>
#include<vector>
#include<math.h>
#include<cstdio>
#include<queue>
using namespace std;
const int N = 105,inf = 100000000;
vector<int>v,tmp;
int w[N][N],dis[N],f;
bool vis[N];
struct node{
	int u,w;
	bool operator<(const node &rhs)const{
		return w > rhs.w;
	}
};
void dijkstra(){
	priority_queue<node>q;
	q.push({0,0});
	dis[0]=0;
	while(!q.empty()){
		auto x = q.top();q.pop();
		int u = x.u,d = x.w;
		if(vis[u])continue;
		vis[u] = true;

		for(int v=0;v<=f;v++){
			if(u==0){
                if(dis[v] > d + w[u][v]){
                    dis[v] = d + w[u][v];
                    if(!vis[v]){
                        q.push({v,dis[v]});
                    }
                }
            }else if(dis[v] > w[u][v] + d + 60){
				dis[v] = w[u][v] + d + 60;
				if(!vis[v]){
                    q.push({v,dis[v]});
                }
			}
		}
	}
}

void init(){
	for(int i=0;i<N;i++){
		dis[i] = inf;
		vis[i] = false;
		for(int j=i+1;j<N;j++)
			w[j][i] = w[i][j] = inf;
	}
}
int main(){
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int n,x;
	string s;

	while(cin>>n>>f){
		v.clear();
		init();
		
		for(int i=0;i<n;i++){
			cin>>x;
			v.push_back(x);
		}
		int p;
		
		for(int i=0;i<n;i++){
			do{
            	scanf("%d",&p);
            	tmp.push_back(p);
        	}while(getchar()!='\n');

      		for(int a=0;a<tmp.size();a++){
      			for(int b=a;b<tmp.size();b++){
      				int x = abs(tmp[b]-tmp[a])*v[i];
      				if(x < w[tmp[b]][tmp[a]]){
      					w[tmp[b]][tmp[a]] = w[tmp[a]][tmp[b]] = x;
      				}
      			}
      		}
		}
		dijkstra();
		if (dis[f] == inf) cout << "IMPOSSIBLE" << endl;
        else cout << dis[f] << endl;
	}
	return 0;
}