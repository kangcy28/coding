#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
struct point
{
    int x,y;
    bool operator<(const point &rhs)const
    {
        return x < rhs.x;
    }
} points[100000];
int main()
{
    memset(points,0,sizeof(points));

    int n,num=0;

    while(cin>>n)
    {
        num++;
        int left[105],on[105],on2[1005],x[105],y[105];

        if(n==0)
            break;
        for(int i=0; i<n; i++)
        {
            cin>>points[i].x>>points[i].y;
            y[i] = points[i].y;
        }
        sort(points,points+n);
        sort(y,y+n);
        int ycnt = unique(y,y+n)-y;

        int ans = 0;
        if(ycnt <= 2)
            ans = n;
        else
        {
            for(int i=0; i<ycnt; i++)
            {
                for(int f=i+1; f<ycnt; f++)
                {
                    int y1 = y[i];
                    int y2 = y[f];

                    int k=0;
                    for(int h=0; h<n; h++)
                    {
                        if(h==0||points[h].x != points[h-1].x)
                        {
                            k++;
                            on[k] = on2[k] = 0;
                            if(h==0)
                                left[k]=0;
                            else
                            {
                                left[k] = left[k-1] + on[k-1] - on2[k-1];
                            }
                        }
                        if(points[h].y <= y2 && points[h].y >= y1)
                            on[k]++;
                        if(points[h].y < y2 && points[h].y > y1)
                            on2[k]++;
                    }
                    if(k<=2)
                    {
                        ans = n;
                        continue;
                    }
                    int M = 0;
                    for(int j=1; j<=k; j++)
                    {
                        ans = max(ans, left[j] + on[j]+M);
                        M = max(M,on2[j]-left[j]);//最大的左邊 因為邊長與左邊的數量是一起的
                    }
                }
            }
        }
        cout<<"Case "<<num<<": "<<ans<<endl;
    }
    return 0;
}
