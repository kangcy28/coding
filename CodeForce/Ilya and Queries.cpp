#include <bits/stdc++.h>
using namespace std;
int pre[100005];
int main(){
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	string s;

	getline(cin,s);

	int q,l,r;
	memset(pre,0,sizeof(pre));
	
	for(int i=1;i<s.size();i++){
		if(s[i]==s[i-1])
			pre[i] = pre[i-1] + 1;
		else
			pre[i] = pre[i-1];
	}
	cin>>q;
	for(int i=0;i<q;i++){
		cin>>l>>r;
		cout<<pre[r-1]-pre[l-1]<<endl;
	}
	return 0;
}