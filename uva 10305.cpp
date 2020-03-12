#include <iostream>
#include <queue>
using namespace std;

int indegree[101];
vector<int>v;
vector<int>G[101];
int main(){
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);

	int n,e,f,t;
	while(cin>>n>>e){
		v.clear();
		if(n==0&&e==0)break;
		for(int i=0;i<101;i++){
			G[i].clear();
			indegree[i] = 0;
		}
		for(int i=0;i<e;i++){
			cin>>f>>t;
			G[f].push_back(t);
			indegree[t]++;
		}
		queue<int>q;

		for(int i=1;i<=n;i++){
			if(indegree[i]==0)
				q.push(i);
		}
		bool first = true;
		while(!q.empty()){
			int k = q.front();q.pop();

			if(first){
				cout<<k;
				first = false;
			}
			else cout<<' '<<k;
			indegree[k] = -1;
			for(auto i : G[k]){
				indegree[i]--;
				if(indegree[i]==0){
					q.push(i);
				}
			}
		}
		
		cout<<endl;
	}
	return 0;
}