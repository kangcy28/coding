#include <bits/stdc++.h>
using namespace std;
int n,w,h,yy[110],T;

struct Point
{
    int x,y;
} p[110];

bool cmp(Point a, Point b)
{
    return (a.x < b.x) || (a.x == b.x && a.y < b.y);
}
void solve()
{
    sort(p,p+n,cmp);

    int ww,hh,cur_x=0,len = unique(p,p+n+2)-p,ansx,ansy,ans=-1;

    for(int i=0; i<len; i++)
    {
        for(int j=i+1; j<len; j++)
        {
            hh = yy[j] - yy[i];

            for(int k=0; k<n; k++)
            {
                if(p[k].y>=yy[j] || p[k].y<=yy[i])
                    continue;
                ww = p[k].x - cur_x;
                ww = min(hh,ww);
                if(ans < ww)
                {
                    ans = ww;
                    ansx = cur_x;
                    ansy = yy[i];
                    ans = ww;
                }
                cur_x = p[k].x;
            }
            ww = w - cur_x;
            ww = min(hh,ww);
            if(ans < ww)
            {
                ansx = cur_x;
                ansy = yy[i];
                ans = ww;
            }
        }
    }
    cout<<ansx<<" "<<ansy<<" "<<ans<<endl;
    if(T)
        cout<<endl;
}

int main()
{
    int x,y;

    cin>>T;
    while(T--)
    {
        cin>>n>>w>>h;

        for(int i=0; i<n; i++)
        {
            cin>>x>>y;
            p[i].x = x;
            p[i].y = y;
            yy[i] = y;
        }
        yy[n] = 0;
        yy[n+1] = h;
        solve();
    }
}
