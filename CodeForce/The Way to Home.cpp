#include <bits/stdc++.h>
using namespace std;
int dp[100005];
int main(){
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	int n,k;
	cin>>n>>k;
	string s;
	getline(cin,s);
	getline(cin,s);
	for(int i=0;i<s.size();i++)
		dp[i] = 10000005;
	dp[0] = 0;
	for(int i=0;i<s.size();i++){
		if(s[i]=='0')continue;
		for(int j=1;j<=k;j++){
			int l = i + j;
			if(l < s.size() && s[l]=='1')
				dp[l] = min(dp[l], dp[i] + 1);
		}
	}
	
	if(dp[s.size()-1]!=10000005)
		cout<<dp[s.size()-1]<<endl;
	else
		cout<<-1<<endl;
	return 0;
}