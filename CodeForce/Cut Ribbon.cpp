#include <bits/stdc++.h>
using namespace std;
int item[5];
int dp[4005];

int main(){
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	int n;

	cin>>n>>item[0]>>item[1]>>item[2];
	for(int i=0;i<4005;i++)
		dp[i] = -1;
	dp[0] = 0;

	for(int i=0;i<3;i++){
		for(int k=0;k<=n/item[i];k++){
			for(int j=4000;j>=item[i];j--){
				if(dp[j-item[i]] != -1)
					dp[j] = max(dp[j],dp[j-item[i]] + 1);
			}
		}
	}
	cout<<dp[n]<<endl;
	return 0;
}