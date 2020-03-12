#include <bits/stdc++.h>
using namespace std;
int dp[100005];
int main(){
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	int n,input;

	while(cin>>n){
		for(int i=0;i<n;i++){
			cin>>input;
			dp[i] = input;
		}
		sort(dp,dp+n);
		int q;

		cin>>q;
		for(int i=0;i<q;i++){
			cin>>input;
			int l = 0, r = n-1, ans=0;
			if(input < dp[0])
				cout<<'0'<<endl;
			else if(input >= dp[n-1])
				cout<<n<<endl;
			else{
				while(l <= r){
					int mid = (l+r)/2; 
					if(dp[mid] <=input && dp[mid+1]>input){
						ans = mid;
						break;
					}else if(dp[mid] > input){
						r = mid - 1;
					}else{
						l = mid + 1;
					}
					//cout<<l<<' '<<r<<' '<<mid<<endl;
				}
				cout<<ans+1<<endl;
			}
			
		}
	}
	return 0;
}