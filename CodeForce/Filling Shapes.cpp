#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	while(cin>>n){
		if(n%2==0){
			int ans = 1;
			n/=2;
			for(int i=0;i<n;i++){
				ans *= 2;
			}
			cout<<ans<<endl;
		}else
			cout<<0<<endl;
	}
}