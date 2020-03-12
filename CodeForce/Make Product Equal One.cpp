#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	long long n,input;
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	while(cin>>n){

		long long ans = 0,n0=0,m=0;
		for(int i=0;i<n;i++){
			cin>>input;
			if(input > 0)
				ans += input - 1;
			else if (input == 0){
				n0++;`
				ans++;
			}else{
				m++;
				ans += abs(input)-1; 
			}
		}
		if(m%2&&n0==0){
			ans += 2; 
		}
		cout<<ans<<endl;
	}
	return 0;
}