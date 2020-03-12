#include <bits/stdc++.h>
using namespace std;
vector<int>primes;
int dp[1125][20];
int main(){
	int n,k;
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	memset(dp,0,sizeof(dp));
	for(int i=2;i<=1120;i++){
		bool flag = false;
		for(int j=2;j<=sqrt(i);j++){
			if(i%j==0){
				flag = true;
				break;
			}
		}
		if(!flag)primes.push_back(i);
	}
	dp[0][0] = 1;
	for(int i=0;i<primes.size();i++){
		for(int j=1120;j>=primes[i];j--){
			for(int k=1;k<20;k++){
				dp[j][k] += dp[j-primes[i]][k-1];
			}
		}
	}
	while(cin>>n>>k){
		if(n==0&&k==0)break;
		cout<<dp[n][k]<<endl;
	}
	return 0;
}