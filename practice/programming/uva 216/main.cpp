#include <iostream>
#include <string.h>
#include <cstdio>
#include <math.h>
using namespace std;
struct locate{
    int x,y;
}m[10];
int dis(locate a, locate b){
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y * b.y));
}
double d[10][10];
bool vis[10];
int minsequence[10],se[10],n;
double mi;
void dfs(int pre, int cnt, double len){
    if(cnt==n){
        if(len < mi){
            mi = len;
            cout<<mi<<endl;
            for(int i=0;i<n;i++)
                minsequence[i] = se[i];
        }
        return;
    }
    for(int i=0;i<n;i++){
        if(!vis[i]){
            vis[i] = true;
            se[cnt] = i;
            dfs(i,cnt+1,len+d[pre][i]);
            vis[i] = false;
        }
    }
}
int main()
{
    int Case=1;
    while(cin>>n){
        memset(vis,false,sizeof(vis));
        for(int i=0;i<n;i++){
            cin>>m[i].x>>m[i].y;
        }
        //for(int i=0;i<n;i++)
        //    d[i][i] = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i!=j)
                    d[i][j] = d[j][i]= dis(m[i],m[j]);
            }
        }
        mi=100000000;
        for(int i=0;i<n;i++){
            se[0] = i;
            vis[i]=true;
            dfs(i,1,0);
            vis[i]=false;
        }
        cout<<"**********************************************************"<<endl;
        printf("Network #%d\n", Case++);
        for (int i = 0; i < n - 1; i++)
            printf("Cable requirement to connect (%d,%d) to (%d,%d) is %.2lf feet.\n", m[minsequence[i]].x, m[minsequence[i]].y, m[minsequence[i + 1]].x, m[minsequence[i + 1]].y, d[minsequence[i]][minsequence[i + 1]]+16);
        printf("Number of feet of cable required is %.2lf.\n", mi + (n-1)*16);
    }
    return 0;
}
