#include <iostream>
#include <algorithm>
using namespace std;
int n,w,h,yy[110],T;

struct point{
  int x,y;
}p[110];

bool cmp(point a, point b){
  if(a.x!=b.x)  return a.x < b.x;
  return a.y < b.y;
}
void solve(){
  sort(p,p+n,cmp);


  int len = unique(yy,yy+n+2)-yy,ansx,ansy,ans=-1;

  for(int i=0;i<len;i++){
    for(int j=i+1;j<len;j++){
      int ww=0,hh=0,cur_x=0;
      hh = yy[j] - yy[i];

      for(int k=0;k<n;k++){
        if(p[k].y>=yy[j] || p[k].y<=yy[i])
          continue;
        ww = p[k].x - cur_x;
        ww = min(hh,ww);
        if(ans < ww){
          ans = ww;
          ansx = cur_x;
          ansy = yy[i];
        }
        cur_x = p[k].x; 
      }
      ww = w - cur_x;
      ww = min(hh,ww);
      if(ans < ww){ 
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

int main() {
  int x,y;

  cin>>T;
  while(T--){
    cin>>n>>w>>h;
    
    for(int i=0;i<n;i++){
      cin>>x>>y;
      p[i].x = x;
      p[i].y = y;
      yy[i] = y;
    }
    yy[n] = 0;
    yy[n+1] = h;
    sort(yy,yy+n+1);
    solve();
  }
  return 0;
}