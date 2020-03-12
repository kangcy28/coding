#include<bits/stdc++.h>
using namespace std;

int main(){
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	
	string s1,s2;
	int a,b;
	string s;
	cin>>s1>>s2;
	cin>>a>>b;
	cin>>s;

	if(s1 == s)
		a--;
	else
		b--;
	cout<<a<<' '<<b<<endl;
	return 0;
}