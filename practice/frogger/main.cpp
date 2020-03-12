#include <iostream>
#include <cstring>
#include <math.h>
#include <iomanip>
using namespace std;
int sx,sy,ex,ey;
struct co
{
    int x,y;
} p[205];
bool vis[205][205];
double mi = 100000000;
int n;
void dfs(int x,int y,double dis){
    if(x==ex && y==ey){
        mi = min(dis,mi);
        return;
    }
    for(int i=0;i<n;i++){
        if(!vis[p[i].x][p[i].y]){
            double d = sqrt(abs(p[i].x-x)*abs(p[i].x-x)+abs(p[i].y-y)*abs(p[i].y-y));
            vis[p[i].x][p[i].y] = true;
            dfs(p[i].x,p[i].y,dis+d);
            vis[p[i].x][p[i].y] = false;
        }
    }
}
int main()
{
    int cnt=1;

    while(cin>>n)
    {
        memset(vis,false,sizeof(vis));
        for(int i=0; i<n; i++)
        {
            if(i==0)
            {
                cin>>sx>>sy;
            }
            else if(i==1)
            {
                cin>>ex>>ey;
                p[i-1].x=ex;
                p[i-1].y=ey;
            }
            else
            {
                cin>>p[i-2].x>>p[i-2].y;
            }
        }
        dfs(sx,sy,0);
        cout<<"Scenario #"<<cnt<<endl;
        cout<<fixed<<setprecision(3)<<"Frog Distance = "<<mi<<endl;
        cnt++;
    }
    return 0;
}
