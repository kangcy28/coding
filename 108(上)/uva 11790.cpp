#include <bits/stdc++.h>
using namespace std;
vector<int>h,w;
int dp[10005];
int main(){
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);

	int Case,n,tmp;
	cin>>Case;

	for(int i=1;i<=Case;i++){
		memset(dp,0,sizeof(dp));
		h.clear();
		w.clear();
		cout<<"Case "<<i<<". ";
		cin>>n;
		for(int j=0;j<n;j++){
			cin>>tmp;
			h.push_back(tmp);
		}
		for(int j=0;j<n;j++){
			cin>>tmp;
			w.push_back(tmp);
		}
		//dp[0] = w[0];
		int ma = 0;
		for(int i=0;i<n;i++){
			dp[i] = w[i];
			for(int j=i-1;j>=0;j--){
				if(h[i] > h[j])
					dp[i] = max(dp[i], dp[j] + w[i]);
			}
			ma = max(ma,dp[i]);
		}
		memset(dp,0,sizeof(dp));
		int ma2 = 0;
		for(int i=n-1;i>=0;i--){
			dp[i] = w[i];
			for(int j=i+1;j<n;j++){
				if(h[i] > h[j])
					dp[i] = max(dp[i], dp[j] + w[i]);
			}
			ma2 = max(ma2,dp[i]);
		}
		if(ma >= ma2){
			cout<<"Increasing ("<<ma<<"). Decreasing ("<<ma2<<")."<<endl;
		}else{
			cout<<"Decreasing ("<<ma2<<"). Increasing ("<<ma<<")."<<endl;
		}
	}
	return 0;
}