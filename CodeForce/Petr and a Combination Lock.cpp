#include <bits/stdc++.h>
using namespace std;
int item[20],n;
bool flag = false;

void dfs(int now,int sum){
	if(n+1 == now){
		if(sum%360==0)
			flag |= 1;
		return;
	}
	
	dfs(now+1,sum+item[now]);
	dfs(now+1,sum-item[now]);
}
int main(){
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>item[i];
	}
	dfs(1,0);
	if(flag)
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;
	return 0;
}