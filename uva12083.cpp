#include <iostream>
#include <vector>
#include <string.h>
#include <math.h>
using namespace std;
const int N = 505;
struct people
{
	int hight;
	string gender,music,exercise;
};
bool adj[N][N];
vector<people>v;
int k(int x){
	if(x<0)return -x;
	return x;
}
bool could(int i,int j){
	int h1 = v[i].hight,h2 = v[j].hight;
	string g1 = v[i].gender, g2 = v[j].gender;
	string m1 = v[i].music, m2 = v[j].music;
	string e1 = v[i].exercise, e2 = v[j].exercise;
	if(k(h1-h2)>40||g1==g2||m1!=m2||e1==e2)
		return true;
	return false;
}
int match[N];
bool vis[N];
int num;
bool dfs(int i){
	for(int j=0;j<num;j++){
		if(!adj[i][j] || vis[j])continue;
		vis[j] = true;
		if(match[j] == -1 || dfs(match[j])){
			match[j] = i;
			return true;
		}
	}
	return false;
}
int main(){
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int Case,hight;
	string gender,music,exercise;
	cin>>Case;
	while(Case--){
		memset(adj,0,sizeof(adj));
		memset(match,-1,sizeof(match));
		v.clear();
		
		cin>>num;
		for(int i=0;i<num;i++){
			cin>>hight>>gender>>music>>exercise;
			v.push_back({hight,gender,music,exercise});
		}
		for(int i=0;i<num;i++){
			if(v[i].gender == "F")continue;
			for(int j=0;j<num;j++){
				if(i==j)continue;
				if(!could(i,j))
					adj[i][j] = true;
			}
		}
		int ans = 0;
		for(int i=0;i<num;i++){
			memset(vis,0,sizeof(vis));
			ans+=dfs(i);
		}
		cout<<num - ans<<endl;
	}
	return 0;
}