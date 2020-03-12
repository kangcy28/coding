#include <bits/stdc++.h>
using namespace std;
int dp[100005];
int main(){
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	int a,b,cnt=0;
	cin>>a>>b;
	if(a==1&&b==1)
		cout<<0<<endl;
	else{
		while(a>0&&b>0){
			if(a>b){
				a-=2;
				b++;
			}else{
				b-=2;
				a++;
			}
			cnt++;
		}
		cout<<cnt<<endl;
	}
	
	return 0;
}