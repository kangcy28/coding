#include <iostream>
using namespace std;
int cost[5] = {1,5,10,20,100};
int main(){
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	long long n;

	while(cin>>n){
		int ans = 0;
		for(int i=4;i>=0;i--){
			int t = n / cost[i];
			ans += t;
			n = n - t * cost[i];
		}
		cout<<ans<<endl;
	}
	return 0;
}
