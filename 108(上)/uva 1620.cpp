#include<bits/stdc++.h>
using namespace std;
vector<int>v;
int main(){
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);

	int Case,input,n;

	cin>>Case;

	while(Case--){
		cin>>n;
		v.clear();
		for(int i=0;i<n;i++){
			cin>>input;
			v.push_back(input);
		}
		int cnt=0;
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				if(v[i] > v[j])
					cnt++;
			}
		}
		if(cnt%2&&n%2)
			cout<<"impossible"<<endl;
		else
			cout<<"possible"<<endl;
	}
	return 0;
}