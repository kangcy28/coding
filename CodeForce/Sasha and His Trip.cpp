#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int n,k;
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	while(cin>>n>>k){
		if(k >= n){
			cout<<n-1<<endl;
		}else{
			int ans = k;
			ans += (1+(n-k))*(n-k)/2-1;
			cout<<ans<<endl;
		}
	}
	return 0;
}