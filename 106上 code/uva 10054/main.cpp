#include <iostream>
//#include <vector>
#include <cstring>
//#include <vector>
using namespace std;
int degree[1010],adj[1010][1010],num;
//struct edge{
  //  int from,to;
//};
//vector<edge>v;

void findeulercircuit(int x){
    for(int j=1;j<=50;j++){
        if(adj[x][j]){
            //cout<<adj[x][j]<<" ";
            adj[x][j]--;
            adj[j][x]--;

            findeulercircuit(j);
            cout<<j<<" "<<x<<endl;
      }
    }
}
int main()
{
    int n,from,to,cnt=0;
    cin>>n;
    while(n--){
        cnt++;
        cout<<"Case #"<<cnt<<endl;
        memset(adj,0,sizeof(adj));
        memset(degree,0,sizeof(degree));

        //int startx,starty;

        cin>>num;
        for(int i=1;i<=num;i++){
            cin>>from>>to;
            /*if(i==0){
                startx = from;
                starty = to;
            }*/
            adj[from][to]++;
            adj[to][from]++;
            degree[from]++;
            degree[to]++;
        }

        bool flag = true;
        for(int i=1;i<=50;i++){
            if(degree[i] % 2){
                cout<<"some beads may be lost"<<endl;
                flag = false;
                break;
            }
        }
        if(flag){
            //v.push_back({startx,starty});
            for(int i=1;i<=50;i++)
                findeulercircuit(i);
            /*for(int i=0;i<v.size();i++){
                cout<<v[i].from<<" "<<v[i].to<<endl;
            }*/
        }
        if(n>0)
            cout<<endl;
    }
    return 0;
}
