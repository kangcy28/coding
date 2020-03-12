#include <iostream>
#include <vector>
#include <map>
#include <cstring>
using namespace std;
string s1,s2;
bool vis[1000];
int d[1000][1000],cnt=0,line,people;
map<string,int>v;
vector<string>names;
void dfs(int u){
    vis[u] = true;
    for(int i=0;i<line;i++){
        if(!vis[i]&&d[u][i]&&d[i][u]){
            cout<<", "<<names[i];
            dfs(i);
        }
    }
}
int main()
{
    while(cin>>line>>people){
        if(!line&&!people)
            break;
        names.clear();
        v.clear();
        memset(vis,false,sizeof(vis));
        memset(d,0,sizeof(d));
        int id = 0;
        string s1,s2;
        for(int i=0;i<people;i++){
            cin>>s1>>s2;
            if(!v.count(s1)){
                v[s1] = id++;
                names.push_back(s1);
            }
            if(!v.count(s2)){
                v[s2] = id++;
                names.push_back(s2);
            }
            d[v[s1]][v[s2]] = 1;
        }
        for(int k=0;k<line;k++){
            for(int i=0;i<line;i++){
                for(int j=0;j<line;j++){
                    d[i][j] = (d[i][j]||d[i][k]&&d[k][j]);
                }
            }
        }
        if(cnt>1)
            cout<<endl;
        cnt++;
        cout<<"Calling circles for data set "<<cnt<<":"<<endl;
        for(int i=0;i<line;i++){
            if(!vis[i]){
                cout<<names[i];
                dfs(i);
                cout<<endl;
            }
        }

    }
    return 0;
}
