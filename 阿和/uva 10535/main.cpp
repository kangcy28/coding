#include <iostream>
#include <algorithm>
//#include <string.h>
#include <math.h>

using namespace std;
const int  N = 1005;
const double eps = 1e-9;
const double pi = acos(-1.0);
struct state{
    double t;
    int k;
}s[N*2];
struct line{
    double x1,x2,y1,y2;
}p[N];
int n,m;
double x,y;

bool cmp(const state& a, const state& b){
    if(fabs(a.t - b.t)>eps)return a.t < b.t;
    return a.k > b.k;
}

int main()
{
    while(cin>>n){
        if(n==0)
            break;
        for(int i=0;i<n;i++){
            cin>>p[i].x1>>p[i].y1>>p[i].x2>>p[i].y2;
        }
        cin>>x>>y;
        m = 0;
        for(int i=0;i<n;i++){
            double l = atan2(p[i].y1 - y,p[i].x1 - x);
            double r = atan2(p[i].y2 - y,p[i].x2 - x);
            if(l > r)
                swap(r,l);
            if(r - l >= pi){
                s[m].k = 1;s[m++].t = -pi;
                s[m].k = -1;s[m++].t = l;
                l = r;r = pi;
            }
            s[m].k = 1;s[m++].t = l;
            s[m].k = -1;s[m++].t = r;
        }
        sort(s,s+m,cmp);
        int ma = 0,ans = 0;
        for(int i=0;i<m;i++){
            ma += s[i].k;
            ans = max(ans,ma);
        }
        cout<<ans<<endl;
    }
    return 0;
}
