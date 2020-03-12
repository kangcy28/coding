#include <iostream>
using namespace std;
int cost[5] = {1,5,10,20,100};
int main(){
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	string s;

	while(cin>>s){
		int ans = 0;
		for(int i=0;i<s.size();i++){
			if(s[i]=='A'){
				int l = 0;
				int r = 0;
				for(int j=0;j<i;j++){
					if(s[j]=='Q')
						l++;
				}
				for(int j=i+1;j<s.size();j++){
					if(s[j]=='Q')
						r++;
				}
				ans += l * r;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
