#include <bits/stdc++.h>
using namespace std;

int main(){
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	string s;

	cin>>s;

	for(int i=1;i<s.size();i++){
		int l=1;
		while(s[i] == s[i-1]){
			i++;
			l++;
		}
		int tmp = 1;
		for(int j=i-l;j<i;j++){
			if(tmp % 2 == 0){
				char c = 'a';
				while(c ==  s[j-1] || c == s[j+1]){
					c++;
				}
				s[j] = c;
			}
			tmp++;
		}
	}
	cout<<s<<endl;
	return 0;
}