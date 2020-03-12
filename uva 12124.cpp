#include<bits/stdc++.h>
using namespace std;
map<string,int>id;
struct component{
	int money;
	int quarity;
};
vector<component>v[1005];
int cnt = 0;
int ID(string a){
	if(!id.count(a))
		id[a] = cnt++;
	return id[a];
}

bool ok(int n, int money, int q){
	int sum = 0;

	for(int i=0;i<cnt;i++){
		int cheapest = money+1;

		for(int j=0;j<v[i].size();j++){
			if(v[i][j].money < cheapest && v[i][j].quarity >= q)
				cheapest = v[i][j].money;
		}
		if(cheapest == money + 1)
			return false;
		sum += cheapest;
	}
	if(sum > money)
		return false;
	return true;
}
int main(){
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);

	int Case;
	string a,b;

	cin>>Case;
	while(Case--){
		cnt = 0;
		int n,money,m,q,maq=0;
		for(int i=0;i<1005;i++)
			v[i].clear();
		id.clear();
		cin>>n>>money;
		for(int i=0;i<n;i++){
			cin>>a>>b>>m>>q;
			v[ID(a)].push_back({m,q});
			maq = max(maq, q);
		}
		int l = 0, r = maq;

		while(l<r){
			int mid = l + (r - l + 1) / 2;

			if(ok(n,money,mid)){
				l = mid;;
			}else{
				r = mid-1;
			}
		}
		cout<<l<<endl;
	}
	return 0;
}