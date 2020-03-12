#include <iostream>
#define INF 100000000
#include <cstring>
#include <queue>
using namespace std;
int matrix[1001][1001];
int cost[1001][1001];
bool vis[1001][1001];
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
int a,b;
struct node{
    int i,j,w;

    bool operator <(const node &rhs)const{
        return w > rhs.w;
    }
};
void dijkstra(){

    priority_queue<node> pq;
    node n1;
    n1.i = 1; n1.j = 1; n1.w = matrix[1][1];
    pq.push(n1);
    cost[1][1] = matrix[1][1];

    while(!pq.empty()){
        node n = pq.top();pq.pop();
        if(vis[n.i][n.j])continue;
        vis[n.i][n.j] = true;
        for(int i=0;i<4;i++){
            if(n.i + dy[i] >= 1 && n.i + dy[i] <= a && n.j + dx[i] >= 1 && n.j + dx[i] <= b
                &&!vis[n.i + dy[i]][n.j + dx[i]]
                && cost[n.i][n.j] + matrix[n.i + dy[i]][n.j + dx[i]] < cost[n.i + dy[i]][n.j + dx[i]]){

                cost[n.i + dy[i]][n.j + dx[i]] = cost[n.i][n.j] + matrix[n.i + dy[i]][n.j + dx[i]];
                node tmp;
                tmp.i = n.i + dy[i];
                tmp.j = n.j + dx[i];
                tmp.w = n.w + matrix[n.i + dy[i]][n.j + dx[i]];
                pq.push(tmp);
            }
        }
    }
}

int main()
{
    int cnt;
    cin>>cnt;

    while(cnt--){

        cin>>a>>b;
        for(int i=1;i<=a;i++)
            for(int j=1;j<=b;j++){
                cost[i][j] = INF;
                vis[i][j] = false;
            }
        for(int i=1;i<=a;i++){
            for(int j=1;j<=b;j++){
                cin>>matrix[i][j];
            }
        }
        dijkstra();
        /*for(int i=1;i<=a;i++){
            for(int j=1;j<=b;j++){
                cout<<cost[i][j]<<" ";
            }
            cout<<endl;
        }*/
        cout<<cost[a][b]<<endl;
    }
    return 0;
}
