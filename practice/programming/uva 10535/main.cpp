#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;
const double pi = acos(-1.0);
const double eps = 1e-9;
struct edge{
    double fx,fy,tx,ty;
}edges[1005];
struct state{
    double t;int k;
}s[2010];

bool cmp(const state &a,const state &b){
    if(a.t!=b.t)
        return a.t < b.t;
    return a.k > b.k;
}
int main()
{
    int n,fx,fy,tx,ty;

    while(cin>>n){
        if(!n)
            break;
        for(int i=0;i<n;i++){
            cin>>edges[i].fx>>edges[i].fy>>edges[i].tx>>edges[i].ty;
        }
        double px,py;
        int m = 0;
        cin>>px>>py;
        for(int i=0;i<n;i++){
            double l = atan2(edges[i].fy - py,edges[i].fx - px);
            double r = atan2(edges[i].ty - py,edges[i].tx - px);
            if(l>r)swap(l,r);
            if(r-l>=pi){
                s[m].t = -pi;
                s[m++].k = 1;
                s[m].t = l;
                s[m++].k = -1;
                l = r;
                r = pi;
            }
            s[m].t = l;s[m++].k = 1;
            s[m].t = r;s[m++].k = -1;
        }
        sort(s,s+m,cmp);
        int ans = 0,c=0;
        for(int i=0;i<m;i++){
            c+=s[i].k;
            //cout<<s[i].t<<endl;
            ans = max(ans,c);
        }
        cout<<ans<<endl;
    }
    return 0;
}
