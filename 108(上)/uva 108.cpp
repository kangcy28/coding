#include <bits/stdc++.h>
using namespace std;
int dp[110][110];
int main(){
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int n;

	while(cin>>n){
		memset(dp,0,sizeof(dp));
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				cin>>dp[i][j];
			}
		}
		for(int i=1;i<n;i++)
			dp[i][0] += dp[i-1][0];
		for(int i=1;i<n;i++){
			dp[0][i] += dp[0][i-1];
		}
		for(int i=1;i<n;i++){
			for(int j=1;j<n;j++){
				dp[i][j] += dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1];
			}
		}
		int ans = 100 * 101 * (-127);
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				for(int a=i;a<n;a++){
					for(int b=j;b<n;b++){
						int subsum = dp[a][b];
						if(i>0)
							subsum -= dp[i-1][b];
						if(j>0)
							subsum -= dp[a][j-1];
						if(i>0&&j>0)
							subsum += dp[i-1][j-1];
						ans = max(ans,subsum);
					}
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}