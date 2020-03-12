#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9,maxn = 101;
int d[101][101];
int main(){
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	int Case,n,e,cnt=1;

	cin>>Case;
	while(Case--){
		cin>>n>>e;
		for(int i=0;i<maxn;i++){
			for(int j=0;j<maxn;j++){
				if(i==j){
					d[i][j] = 0; 
					continue;
				}
				d[j][i] = d[i][j] = inf;
			}
		}
		int f,t;
		for(int i=0;i<e;i++){
			cin>>f>>t;
			d[f][t] = d[t][f] = 1;
		}
		int st,en;
		cin>>st>>en;
		for(int k=0;k<n;k++){
			for(int i=0;i<n;i++){
				for(int j=0;j<n;j++){
					if(d[i][j] > d[i][k] + d[k][j])
						d[j][i] = d[i][j] = d[i][k] + d[k][j];
				}
			}
		}
		int ma = 0;
		for(int i=0;i<n;i++){
			if(d[st][i] != inf && d[i][en] != inf)
			ma = max(ma, d[st][i] + d[i][en]);
		}
		cout<<"Case "<<cnt<<": "<<ma<<endl;
		cnt++;
	}
	return 0;
}