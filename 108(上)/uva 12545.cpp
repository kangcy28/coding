#include<bits/stdc++.h>
using namespace std;
vector<int>v;
int main(){
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int Case;
	string s1,s2;

	cin>>Case;
	
	for(int x=1;x<=Case;x++){
		cin>>s1>>s2;
		int ans1 = 0, ans2 = 0,num1=0,num2=0,q=0;
		for(int i=0;i<s1.size();i++){
			if(s1[i]=='0' && s2[i]=='1')
				ans1++;
			else if(s1[i]=='1' && s2[i]=='0')
				ans2++;
			else if(s1[i]=='?')
				q++;
			if(s1[i]=='1')
				num1++;
			if(s2[i]=='1')
				num2++;
		}
		cout<<"Case "<<x<<": ";
		if(num1 > num2)cout<<"-1"<<endl;
		else{
			cout<<max(ans1,ans2)+q<<endl;
		}
	}
	return 0;
}