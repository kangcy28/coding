#include<bits/stdc++.h>
using namespace std;
vector<int>v;
int main(){
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);

	int Case,n,input;

	cin>>Case;
	int cnt = 0;
	bool flag = false;
	while(Case--){
		flag = false;
		cnt=0;
		cin>>n;
		v.clear();
		for(int i=0;i<n;i++){
			cin>>input;
			v.push_back(input);
		}
		
		while(!flag){
			cnt++;
			int tmp = v[0];
			for(int i=0;i<n-1;i++){
				v[i] = abs(v[i+1] - v[i]);
			}
			v[n-1] = abs(tmp - v[n-1]);
			//for(int i=0;i<n;i++)
			//	cout<<v[i]<<' ';
			//cout<<endl;
			if(cnt == 1000)
				break;
			bool f = false;
			for(int i=0;i<n;i++){
				if(v[i] != 0)
					f = true;
			}
			if(!f)
				flag = true;
		}
		if(flag){
			cout<<"ZERO"<<endl;
		}else{
			cout<<"LOOP"<<endl;
		}
	}
	return 0;
}