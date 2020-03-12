#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int>G[1501];
int dp[1510][2];
bool vis[1510];
void addedge(int from,int to){
	G[from].push_back(to);
	G[to].push_back(from);
}

void dfs(int cur){
	dp[cur][0] = 0;
	dp[cur][1] = 1;
	vis[cur]=true;
	
	for(auto it : G[cur]){
		if(vis[it])continue;
		dfs(it);
		dp[cur][0] += dp[it][1];
		dp[cur][1] += min(dp[it][0],dp[it][1]);
		
	}
}
int solve(int n){
	int ans=0;
	for(int i=0;i<n;i++)
		vis[i] = false;
	for(int i=0;i<n;i++){
		if(vis[i])continue;
		dfs(i);
		ans += min(dp[i][0],dp[i][1]);
	}
	return ans;
}
int main(){
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	int n,num,from,to;
	char c;

	while(cin>>n){
		if(n==0)break;
		for(int i=0;i<1501;i++)
			G[i].clear();
		
		for(int i=0;i<n;i++){
			cin>>from;
			cin>>c;
			cin>>c;
			cin>>num;
			cin>>c;
			
			for(int i=0;i<num;i++){
				cin>>to;
				addedge(from,to);
			}
		}
		cout<<solve(n)<<endl;
	}
	return 0;
}