#include <bits/stdc++.h>
using namespace std;

vector<char>v;
int main(){
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int n,k;
	char c;
	string s;

	cin>>n>>k;

	getline(cin,s);
	getline(cin,s);

	for(int i=0;i<k;i++){
		cin>>c;
		v.push_back(c);
	}
	long long cnt = 1,ans = 0;

	for(int i=0;i<s.size();i++){
		bool flag = false;
		for(int j=0;j<v.size();j++){
			if(v[j] == s[i]){
				flag = true;
				break;
			}
		}
		if(flag){
			ans += cnt++;
		}else{
			cnt = 1;
		}
	}

	cout<<ans<<endl;
	return 0;
}