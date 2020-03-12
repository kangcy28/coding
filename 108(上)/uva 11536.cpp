#include<bits/stdc++.h>
using namespace std;
int t[1000005];
int cnt[1000005];
int main(){
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int Case,n,m,k;

	cin>>Case;

	for(int h=1;h<=Case;h++){
		memset(cnt,0,sizeof(cnt));
		cin>>n>>m>>k;
		t[1] = 1;
		t[2] = 2;
		t[3] = 3;
		for(int i=4;i<=n;i++){
			t[i] = (t[i-1]+t[i-2]+t[i-3]) % m + 1;
		}
		int f=1,e=0,x=0,length = n;
		while(e <= n){
			//cout<<f<<' '<<e<<endl;
			e++;
			if(t[e]<=k && cnt[t[e]]==0)
				x++;
			cnt[t[e]]++;

			while(x==k && e <= n){
				if(t[f] <= k && cnt[t[f]]==1){
					length = min(length,e-f+1);
					//cout<<length<<endl;
					x--;
				}
				cnt[t[f]]--;
				f++;
			}
		}
		cout<<"Case "<<h<<": ";
		if(length==n)
			cout<<"sequence nai"<<endl;
		else
			cout<<length<<endl;
	}
	return 0;
}