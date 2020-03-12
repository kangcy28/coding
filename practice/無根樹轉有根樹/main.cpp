#include <iostream>
#include <vector>
using namespace std;
int m,p[1000];
vector<int>G[1000];
void read_tree(){
    int u,v;

    for(int i=0;i<m;i++){
        cin>>u>>v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
}

void dfs(int v, int fa){
    int s = G[v].size();

    for(int i=0;i<s;i++){
        int u = G[v][i];
        if(u != fa){
            dfs(u,p[u] = v);
        }
    }
}
int main()
{
    int n;
    while(cin>>n){
        cin>>m;
        read_tree();
        cin>>root;
        p[root] = -1;
        dfs(root,-1);

    }
    return 0;
}
