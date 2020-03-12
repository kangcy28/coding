#include <bits/stdc++.h>
using namespace std;
struct item{
	int n;
	int k;
};
vector<item>items;
int dp[8];
int main(){
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	int n,input;
	string str;

	cin>>n;
	for(int i=0;i<n;i++){
		cin>>input;
		cin>>str;
		int num = 0;
		for(int j=0;j<str.size();j++){
			if(str[j] == 'A'){
				num |= 1<<0;
			}else if(str[j] == 'B')
				num |= 1<<1;
			else if(str[j] == 'C'){
				num |= 1<<2;
			}
		}
		items.push_back({input,num});
	}
	for(int i=0;i<8;i++)
		dp[i] = 10000000;
	dp[0] = 0;
	for(int i=0;i<items.size();i++){
		for(int j=0;j<=7;j++){
			dp[j|items[i].k] = min(dp[j]+items[i].n, dp[j|items[i].k]); 
		}
	}
	if(dp[7]==10000000){
		cout<<"-1"<<endl;
	}else{
		cout<<dp[7]<<endl;
	}
	return 0;
}