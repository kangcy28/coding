#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	ll n;
	cin>>n;

	int ans = 0;
	for(ll i = 2; i < n; i++){
		ans += i * (i+1);
	}
	cout<<ans<<endl;
	return 0;
}