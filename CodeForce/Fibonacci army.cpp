#include <bits/stdc++.h>
using namespace std;
long long dp[25];
int main(){
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	int n;
	dp[0] = 1;
	dp[1] = 1;
	cin>>n;
	if(n==0)cout<<1<<endl;
	else if(n==1)cout<<1<<endl;
	else{
		for(int i=2;i<=n;i++){
			dp[i] = dp[i-2] + dp[i-1];
		}
		cout<<dp[n]<<endl;
	}
	return 0;
}