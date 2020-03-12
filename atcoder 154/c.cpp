#include<bits/stdc++.h>
using namespace std;
set<int>s;
int main(){
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	
	int n,input;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>input;
		s.insert(input);
	}
	if(s.size()==n)
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;
	return 0;
}