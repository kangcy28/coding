#include <iostream>
#define inf 1e6
using namespace std;
int d[1000][1000];
int num_node,edges,query,u,v,w;
void floyd(){
    for(int k=1;k<=num_node;k++){
        for(int i=1;i<=num_node;i++){
            for(int j=1;j<=num_node;j++){
                d[i][j] = min(d[i][j],max(d[i][k],d[k][j]));
            }
        }
    }
}
void init(){
    for(int i=1;i<=num_node;i++){
        for(int j=1;j<=num_node;j++){
            d[i][j] = inf;
        }
    }
}
int main()
{

    int cnt = 0;
    while(cin>>num_node>>edges>>query){
        init();
        if(!num_node&&!edges&&!query)
            break;
        for(int i=0;i<edges;i++){
            cin>>u>>v>>w;
            d[u][v] = d[v][u] = w;
        }
        floyd();
        if(cnt)cout<<endl;
        cnt++;
        cout<<"Case #"<<cnt<<endl;
        for(int i=0;i<query;i++){
            cin>>u>>v;
            if(d[u][v]==inf)
                cout<<"no path"<<endl;
            else
                cout<<d[u][v]<<endl;
        }
    }
    return 0;
}
