#include<iostream>
#include<vector>
#include<math.h>
using namespace std;
int maps[10][10];
vector<vector<int>>vv;


bool judge(int n, int *col){
	for(int i=0;i<n;i++){
		if(col[i] == col[n] || abs(col[n] - col[i]) == abs(n - i))
			return false;
	}
	return true;
}

void dfs(int n, int *col){
	if(n==7){
		for(int i=0;i<8;i++){
			col[n] = i;
			if(judge(n,col)){
				vector<int>v;
				for(int i=0;i<8;i++){
					v.push_back(col[i]);
				}
				vv.push_back(v);
			}
		}
	}else{
		for(int i=0;i<8;i++){
			col[n] = i;
			if(judge(n,col)){
				dfs(n+1,col);
			}
		}
	}
}
int main(){
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);

	int Case, col[10];
	dfs(0,col);
	
	cin>>Case;
	while(Case--){
		for(int i=0;i<8;i++){
			for(int j=0;j<8;j++){
				cin>>maps[i][j];
			}
		}
		int ans = 0;
		for(int i=0;i<vv.size();i++){
			vector<int>v = vv[i];
			int sum = 0;
			for(int i=0;i<8;i++){
				sum += maps[i][v[i]];
			}
			ans = max(ans,sum);
		}
		printf("%5d\n", ans);;
	}
}