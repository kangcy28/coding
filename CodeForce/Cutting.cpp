#include <bits/stdc++.h>
using namespace std;
vector<int>v;
vector<int>arr;
int main(){
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	int n,k,input;

	cin>>n>>k;

	for(int i=0;i<n;i++){
		cin>>input;
		v.push_back(input);
	}
	int odd=0,even=0;
	for(int i=0;i<n-1;i++){
		if(v[i] % 2){
			odd++;
		}else{
			even++;
		}
		if(odd == even){
			arr.push_back(abs(v[i+1]-v[i]));
		}
	}
	int ans = 0;

	sort(arr.begin(),arr.end());
	for(int i=0;i<arr.size();i++){
		if(arr[i] <= k){
			k -= arr[i];
			ans++;
		}
	}
	cout<<ans<<endl;
	return 0;
}