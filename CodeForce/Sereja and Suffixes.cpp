#include <bits/stdc++.h>
using namespace std;
int suf[100005],num[100005],cnt[100005];
int main(int argc, char const *argv[])
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	int n,m;
	memset(cnt,0,sizeof(cnt));
	memset(suf,0,sizeof(suf));
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>num[i];
	}
	for(int i=n-1;i>=0;i--){
		if(cnt[num[i]]==0){
			suf[i] = suf[i+1] + 1;
		}else{
			suf[i] = suf[i+1];
		}
		cnt[num[i]]++;
	}
	
	int input;

	for(int i=0;i<m;i++){
		cin>>input;
		cout<<suf[input-1]<<endl;
	}
	return 0;
}