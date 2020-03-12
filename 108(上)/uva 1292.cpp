#include<bits/stdc++.h>
using namespace std;
vector<int>g[100000];
int n,dp[100000][2],Case;
bool vis[100000];
void dfs(int x){
	dp[x][1] = 1;
	dp[x][0] = 0;
	vis[x] = true;
	for(int i=0;i<g[x].size();i++){
		int v = g[x][i];
		if(vis[v])continue;

		dfs(v);
		dp[x][0] += dp[v][1];
		dp[x][1] += min(dp[v][1], dp[v][0]);
	}
}
int solve(){
	int ans=0;
	memset(vis,false,sizeof(vis));
	for(int i=0;i<Case;i++){
		if(vis[i])continue;
		dfs(i);
		ans += min(dp[i][0],dp[i][1]);
	}
	return ans;
}

int main(){
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);

	int u,m;
	char c;
	while(cin>>Case){
		for(int i=0;i<100000;i++)
			g[i].clear();
		for(int j=0;j<Case;j++){
			cin>>u>>c>>c>>n>>c;
			for(int i=0;i<n;i++){
				cin>>m;
				g[u].push_back(m);
				g[m].push_back(u);
			}
		}
		cout<<solve()<<endl;
	}
	return 0;
}