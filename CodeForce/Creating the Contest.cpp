#include <bits/stdc++.h>
using namespace std;
vector<int>v;
int main(){
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	int n,input;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>input;
		v.push_back(input);
	}
	int ans = 0;
	for(int i=0;i<n;i++){
		int j = i;
		while(j+1<n && v[j+1] <= v[j] * 2){
			j++;
		}
		ans = max(ans, j-i+1);
		i = j;
	}
	cout<<ans<<endl;
	return 0;
}