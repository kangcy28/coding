#include <bits/stdc++.h>
#include <string>
using namespace std;
int le(int n){
	int cnt=0;
	while(n>0){
		n /= 10;
		cnt++;
	}
	return cnt;
}
int main(){
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int Case,n,pre[50000],cnt[50000];
	

	for(int i=1;i<50000;i++)
		cnt[i] = le(i);
	pre[1] = 1;
	for(int i=2;i<50000;i++){
		pre[i] = pre[i-1] + cnt[i];
	}
	cin>>Case;
	while(Case--){
		cin>>n;
		int index = 1;
		while(n > pre[index]){
			n -= pre[index];
			index++;
		}

		string str="";
		for(int i=1;i<=index;i++){
			string s = std::to_string(i);
			str += s;
		}
		cout<<str[n-1]<<endl;

	}
	return 0;
}