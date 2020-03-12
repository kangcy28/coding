#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
ll L,D,N;

struct v{
    ll x,y;
    ll l,r;
    v(){};
    v(ll a, ll b):x(a),y(b){
        ll D2 = D*D,y2 = y*y;
        ll t = sqrt(D2 - y2);
        l = max((ll)0,(ll)ceil(x - t));
        r = min((ll)L,(ll)floor(x + t));
    }
    bool operator<(const v &rhs)const{
        return r < rhs.r;
    }
};
int main()
{
    while(cin>>L){
        vector<v> vv;
        cin>>D>>N;
        int a1,a2;
        for(int i=0;i<N;i++){
            cin>>a1>>a2;
            vv.push_back(v(a1,a2));
        }
        sort(vv.begin(),vv.end());
        ll pre = vv[0].r,ans = 1;
        for(int i=0;i<N;i++){
            if(vv[i].l > pre){
                ans++;
                pre = vv[i].r;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
