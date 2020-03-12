#include <bits/stdc++.h>
using namespace std;
vector<int>ma,wo;
int main(){
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	int n,m,input;

	cin>>n;
	for(int i=0;i<n;i++){
		cin>>input;
		ma.push_back(input);
	}
	cin>>m;
	for(int i=0;i<m;i++){
		cin>>input;
		wo.push_back(input);
	}
	sort(ma.begin(),ma.end());
	sort(wo.begin(),wo.end());

	int i=0,j=0,ans=0;
	
	while(i<ma.size() && j<wo.size()){
		if(abs(ma[i]-wo[j])<=1){
			//cout<<ma[i]<<' '<<wo[j]<<endl;
			i++;
			j++;
			ans++;
		}else if(ma[i] > wo[j])
			j++;
		else if(ma[i] < wo[j])
			i++;
	}
	cout<<ans<<endl;
	return 0;
}