#include <iostream>
#include <algorithm>

using namespace std;
int n;

struct item
{
    int id;
    double x,y,w,d,h;

    bool operator<(const item& rhs)const
    {
        return x < rhs.x ||(x == rhs.x && y < rhs.y);
    }
} a[105];
double b[210];

bool cover(int n,double mx)
{
    return ((a[n].x <= mx) && (mx <= a[n].x + a[n].w));
}
bool visible(int i, double mid)
{
    if(!cover(i,mid))
        return false;
    for(int k=0; k<n; k++)
    {
        if(a[i].h <= a[k].h && a[i].y > a[k].y && cover(k,mid))
            return false;
    }
    return true;
}

int main()
{
    double x,y,w,d,h;
    int cas=0;

    while(cin>>n&&n)
    {

        for(int i=0; i<n; i++)
        {
            cin>>x>>y>>w>>d>>h;
            a[i].x = x;
            a[i].y = y;
            a[i].w = w;
            a[i].d = d;
            a[i].h = h;
            a[i].id = i+1;
            b[i*2] = x,b[i*2+1] = x + w;//store all x
        }
        sort(a,a+n);
        sort(b,b+2*n);
        int m = unique(b,b+2*n)-b;
        if(cas)
            cout<<endl;
        cout<<"For map #"<<++cas<<", the visible buildings are numbered as follows:"<<endl<<a[0].id;
        for(int i=1; i<n; i++)
        {
            bool vis = false;

            for(int j=0; j<m-1; j++)
            {
                if(visible(i,(b[j] + b[j+1])/2))
                {
                    vis = true;
                    break;
                }
            }
            if(vis)cout<<" "<<a[i].id;
        }
        cout<<endl;
    }
    return 0;
}
