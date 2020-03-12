#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;
map<string,int>maps;
map<int,string>mapss;
vector<string>v;
int main(){
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	int Case,num,cnt=0;
	string s;
	cin>>Case;

	while(Case--){

		v.clear(); 
		maps.clear();
		mapss.clear();

		cin>>num;
		cin>>ws;
		for(int i=0;i<num;i++){
			getline(cin,s);
			v.push_back(s);
		}
		for(int i=0;i<num;i++){
			getline(cin,s);
			maps.insert({s,i});
			mapss.insert({i,s});
		}
		int ans=-1;
		for(int i=0;i<num;i++){
			string tmp = v[i];
			int index = maps[tmp];

			for(int j=0;j<i;j++){
				string x = v[j];
				int xid = maps[x];

				if(xid > index)
					ans = max(ans,index);
			}
		}
		for(int i=ans;i>=0;i--){
			cout<<mapss[i]<<endl;
		}
		cout<<endl;
	}
	return 0;
}
/*把後來編號1...n
看先前的哪些上面有比他大的那就找最大有比他大的編號*/