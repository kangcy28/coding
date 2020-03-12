#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
double length,w;
int num,ans;

struct item{
  double r,l;
}k[10010];

bool cmp(item a, item b){
  if(a.l != b.l) return a.l < b.l;
  return a.r > b.r;
}
int solve(int tot){
  if(k[0].l > 0){
    return -1;
  }
  double cur_r =0;
  ans = 0;
  int i = 0;
  double ma = 0;

  while(i < tot){
    bool p = false;
    while(i < tot && k[i].l  <= cur_r){
      ma = max(ma,k[i].r);
      i++;
      p = true;
    }
    if(!p)return -1;
    cur_r = ma;
    ans++;
    if(cur_r >= length)return ans;
  }

  if(cur_r  < length) return -1;
  return ans;
}

int main() {
  double po;
  double d;
  
  while(cin>>num>>length>>w){
    int tot = 0;
    for(int i=0;i<num;i++){
      cin>>po>>d;
      if(d <= w / 2) continue;
      double r = sqrt((d * d) - w * w / 4); 

      k[tot].l = po - r;
      k[tot].r = po + r;
      tot++;
    }
    sort(k,k+tot,cmp);
    ans = solve(tot);
    cout<<ans<<endl;
  }
}