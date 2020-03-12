#include <bits/stdc++.h>
using namespace std;

int main(){
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	int Case,n,a,b,c;
	string s;
	cin>>Case;
	while(Case--){
		cin>>n;
		cin>>a>>b>>c;
		getline(cin,s);
		getline(cin,s);
		int na=0,nb=0,nc=0;
		for(int i=0;i<s.size();i++){
			if(s[i]=='R')
				na++;
			else if(s[i]=='P')
				nb++;
			else if(s[i]=='S')
				nc++;
		}
		int ans = 0;
		ans += min(na,b) + min(nb,c) + min(nc,a);
		if(2 * ans >= n){
			cout<<"YES"<<endl;
			string str="";
			for(int i=0;i<s.size();i++){
				if(s[i]=='R' && b){
					str += 'P';
					b--;
				}else if(s[i]=='P' && c){
					str += 'S';
					c--;
				}else if(s[i]=='S' && a){
					str += 'R';
					a--;
				}else{
					str += '_';
				}
			}
			for(int i=0;i<s.size();i++){
				if(str[i] == '_'){
					if(a){
						a--;
						str[i] = 'R';
					}else if(b){
						b--;
						str[i] = 'P';
					}else{
						c--;
						str[i] = 'S';
					}
				}
			}
			cout<<str<<endl;
		}else{
			cout<<"NO"<<endl;
		}
	}
	return 0;
}