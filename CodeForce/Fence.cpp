#include <bits/stdc++.h>
using namespace std;
int pre[200005];
int num[200005];
int main(){
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	int n,k,tmp;

	cin>>n>>k;

	for(int i=1;i<=n;i++){
		cin>>num[i];
	}
	
	pre[0] = 0;
	for(int i=1;i<=n;i++){
		pre[i] = pre[i-1] + num[i];
	}
	int mi = 100000000,index=1;
	for(int i=k;i<=n;i++){
		int f = i-k;
		if(f<0)continue;
		//cout<<f<<' ';
		//cout<<pre[i]-pre[f]<<endl;
		if(pre[i]-pre[f]<mi){
			mi = min(mi, pre[i] - pre[f]);
			index = f+1;
		}
	}
	cout<<index<<endl;
	return 0;
}