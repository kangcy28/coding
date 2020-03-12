#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int Case,d,u,v;
	cin>>Case;
	for(int i=1;i<=Case;i++){
		cin>>d>>u>>v;
		cout<<"Case "<<i<<": ";
		if(u==0||u>=v||v==0)
			cout<<"can't determine"<<endl;
		else{
			double a = (double)d / v;
			double b = (double)d / sqrt(v*v-u*u);
			
			cout<<fixed<<setprecision(3)<<b-a<<endl;
		}
	}
	return 0;
}