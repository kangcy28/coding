#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int>v;
int main(){
	int n,input,sum,cnt=0;
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	while(cin>>n){
        if(cnt)cout<<endl;
        cnt++;
		v.clear();
		for(int i=0;i<n;i++){
			cin>>input;
			v.push_back(input);
			//cout<<input<<endl;
		}
		cin>>sum;
		sort(v.begin(),v.end());

		int ans = 10000000,f=0,e=v.size()-1,x;
		int a=0,b=0;
		while(f<e){
            //cout<<v[f]<<' '<<v[e]<<endl;
			x = v[f] + v[e];
			if(x==sum){
				if(ans > abs(v[f]-v[e])){
					b = v[e];
					a = v[f];
				}
				f++;
				e--;
			}else if(x > sum)
				e--;
			else{
				f++;
			}
		}
		cout<<"Peter should buy books whose prices are "<<a<<" and "<<b<<'.'<<endl;
	}
	return 0;
}
