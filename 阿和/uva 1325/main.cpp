#include <iostream>
#include <math.h>
#include <algorithm>
#include <iomanip>
#include <vector>
using namespace std;
struct star{
    int x,y,z,p;
}s[1010];
struct edge{
    int from,to,dis;
    bool operator<(const edge &rhs)const{
            return dis < rhs.dis;
    }
};

int dis(star a,star b){
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y) + (a.z - b.z) * (a.z - b.z);
}

int temp[1010];
int main()
{
    int n;

    while(cin>>n){
        vector<edge>Edges;
        int cnt = 0,ans = 0;
        int ansdis = 0;
        for(int i=0;i<n;i++){
            cin>>s[i].x>>s[i].y>>s[i].z>>s[i].p;
            temp[i] = 1;
        }
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                Edges.push_back(edge{i,j,dis(s[i],s[j])});
            }
        }
        sort(Edges.begin(),Edges.end());
        int h=0,q=0;
        while(h < (int)Edges.size()){
            q = h;

            while(q < (int)Edges.size() && Edges[h].dis == Edges[q].dis){
                int u = Edges[q].from, v = Edges[q].to;

                if(s[u].p != s[v].p){
                    if(--temp[u] == -1)cnt++;
                    if(--temp[v] == -1)cnt++;
                }else{
                    if(++temp[u] == 0)cnt--;
                    if(++temp[v] == 0)cnt--;
                }
                q++;
            }
            if(ans < cnt){
                ans = cnt;
                ansdis = Edges[h].dis;
            }
            h = q;
        }
        cout<<ans<<endl;
        cout<<fixed<<setprecision(4)<<sqrt(ansdis)<<endl;
    }
    return 0;
}
