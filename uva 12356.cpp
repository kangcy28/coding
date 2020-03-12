#include<iostream>
#include<string.h>
using namespace std;
int l[100005];
int r[100005];
int main(){
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);

	int n,m,a,b;

	while(cin>>n>>m){
		if(n==0&&m==0)break;
		for(int i=1;i<=n;i++){
			l[i] = i-1;
			r[i] = i+1;
		}
		l[0] = r[0] = r[n] = 0;
		for(int i=0;i<m;i++){
			cin>>a>>b;
			
			if(l[a]==0)	cout<<'*';
			else		cout<<l[a];

			if(r[b]==0)cout<<' '<<'*';
			else		cout<<' '<<r[b];

			cout<<endl;
			r[l[a]] = r[b];
			l[r[b]] = l[a];
		}
		cout<<"-"<<endl;
	}
	return 0;
}