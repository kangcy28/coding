#include <iostream>
#include <map>
#include <vector>
#include <queue>
#define DEBUG
using namespace std;

string str[101];
map<string,int>Index;
vector<int>G[101];
int indegree[101];
int main(){
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int n,cnt=0;

	while(cin>>n){
		
		cout<<"Case #"<<++cnt<<": Dilbert should drink beverages in this order:";
		
		Index.clear();
		for(int i=0;i<n;i++){
			cin>>str[i];
			Index[str[i]] = i;
			indegree[i] = 0;
			G[i].clear();
		}
		int m;
		cin>>m;

		string a,b;
		for(int i=0;i<m;i++){
			cin>>a>>b;
			int x = Index[a];
			int y = Index[b]; 
			indegree[y]++;
			G[x].push_back(y);
		}
		
		priority_queue<int,vector<int>,greater<int>>q;

		for(int i=0;i<n;i++)
			if(indegree[i]==0)
				q.push(i);
		while(!q.empty()){
			int k = q.top();q.pop();

			indegree[k] = -1;
			cout<<' '<<str[k];
			for(auto it : G[k]){
				indegree[it]--;
				if(indegree[it]==0)
					q.push(it);
			}
		}
		cout<<'.'<<endl;
		cout<<endl;
	}
	return 0;
}