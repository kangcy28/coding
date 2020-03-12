#include<bits/stdc++.h>
using namespace std;
vector<int>v;
const inf = 1000000;
int dp[50];
int main(){
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int cnt=0,n,input;
	while(cin>>n){
		cnt++;
		v.clear();
		for(int i=0;i<n;i++){
			cin>>input;
			v.push_back(input);
		}
		bool flag = false;
		for(int i=1;i<v.size();i++){
			if(v[i-1]>v[i]){
				flag = true;
			}
		}
		
	}
	return 0;
}