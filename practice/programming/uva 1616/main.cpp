#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
#define maxn 1000000
#define INF 1000010

const double eps = 1e-9;
struct k{
    double r,l;
}a[maxn];
int n;
bool cmp(k a,k b){
    return a.l < b.l;
}

bool judge(double target){
    bool f = true;
    double s = 0;

    for(int i=0;i<n&&f;i++){
        if(s < a[i].l){
            if(a[i].l + target <= a[i].r)
                s = a[i].l + target;
            else
                f = false;
        }else{
            if(s + target <= a[i].r)
                s = s + target;
            else
                f = false;
        }
    }
    return f;
}
int main()
{
    while(cin>>n){
        for(int i=0;i<n;i++){
            cin>>a[i].l>>a[i].r;
        }
        sort(a,a+n,cmp);
        double L=0, R=INF;
        while(R - L > eps){
            double mid = (R+L)/2;
            if(judge(mid))L = mid;
            else R = mid;
        }
        double ans = L;
        int rp = 0,rq = 1;

        for(int p,q=1;q<=n;q++){
            p = round(q * ans);
            if(fabs((double)p/q - ans) < fabs((double)rp/rq - ans)){
                rp = p;
                rq = q;
            }
        }
        cout<<rp<<"/"<<rq<<endl;
    }
    return 0;
}
