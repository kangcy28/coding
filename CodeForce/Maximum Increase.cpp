#include <bits/stdc++.h>
using namespace std;
vector<long long>v;
long long dp[100005];
int main(){
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	int n,input;
	while(cin>>n){
		for(int i=0;i<n;i++){
			cin>>input;
			v.push_back(input);
			dp[i] = 1;
		}
		long long  ans = 1;
		for(int i=1;i<n;i++){
			if(v[i-1] < v[i]){
				dp[i] = dp[i-1] + 1;
				ans = max(ans, dp[i]);
			}

		}
		cout<<ans<<endl;
	}
	return 0;
}