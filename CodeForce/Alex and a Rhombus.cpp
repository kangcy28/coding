#include <iostream>
using namespace std;
int dp[105];
int main(){
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	int n;
	dp[1] = 1;

	for(int i=2;i<=100;i++){
		dp[i] = dp[i-1] + i*4-4;
	}
	while(cin>>n){
		cout<<dp[n]<<endl;
	}
	return 0;
}