#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll pre1[200005],pre2[200005],num1[200005],num2[200005];

int main(){
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	int n,q;

	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>num1[i];
		num2[i] = num1[i];
	}
	sort(num2+1,num2+1+n);
	pre1[0]=0;
	pre2[0]=0;
	for(int i=1;i<=n;i++){
		pre1[i] = pre1[i-1] + num1[i];
		pre2[i] = pre2[i-1] + num2[i];
	}
	cin>>q;
	int t,l,r;
	for(int i=0;i<q;i++){
		cin>>t>>l>>r;
		if(t==1){
			cout<<pre1[r]-pre1[l-1]<<endl;
		}else{
			cout<<pre2[r]-pre2[l-1]<<endl;
		}
	}
	return 0;
}