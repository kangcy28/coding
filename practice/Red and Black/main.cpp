#include <iostream>
#include <queue>
using namespace std;
char maps[25][25];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
bool vis[25][25];
int px,py,n,m;
int solve(){
    queue<pair<int,int>>q;
    q.push({px,py});
    int ans=1;
    while(!q.empty()){
        pair<int,int>p = q.front();q.pop();

        for(int i=0;i<4;i++){
            if(!vis[p.second+dy[i]][p.first+dx[i]] && p.first+dx[i]>=0&&p.first+dx[i]<n
               &&p.second+dy[i]>=0&&p.second+dy[i]<m
               &&maps[p.second+dy[i]][p.first+dx[i]]=='.'){
                ans++;
                vis[p.second+dy[i]][p.first+dx[i]] = true;
                q.push({p.first+dx[i],p.second+dy[i]});
            }
        }
    }
    return ans;
}
int main() {
    while(cin>>n>>m){
        for(int i=0;i<25;i++){
            for(int j=0;j<25;j++){
                vis[i][j] = false;
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
              cin>>maps[i][j];
              if(maps[i][j]=='@'){
                px = j;
                py = i;
              }
            }
        }
        cout<<solve()<<endl;
    }
}
