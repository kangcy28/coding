#include <bits/stdc++.h>
using namespace std;
int dpu[100005],dpl[100005];

int main(int argc, char const *argv[])
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	
	string s;

	while(cin>>s){
		int num = 0;
		int u = 0;
		for(int i=0;i<s.size();i++){
			if(s[i]>='A'&&s[i]<='Z'){
				u = max(u,num);
				num = 0;
			}else{
				num++;
				
			}
		}
		int l = 0;
		num = 0;
		for(int i=s.size()-1;i>=0;i--){
			if(s[i]>='a'&&s[i]<='z'){
				l = max(l,num);
				num = 0;
			}else{
				num++;
			}
		}
	}
	
	return 0;
}