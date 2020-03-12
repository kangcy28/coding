#include <iostream>
#include <algorithm>
using namespace std;
int p[10001],r[10010];

struct edge{
  int x,y,v;
};

edge D[100000];
int find(int x){
  if(p[x]==x)
    return x;
  else
    return p[x] = find(p[x]);
}

void init(int a){
  for(int i=0;i<=a;i++){
    p[i] = i;
    r[i] = 1;
  }
}

bool joint(int x,int y){
  int a = find(x),b = find(y);

  if(a != b){
    if(r[a] > r[b]){
      r[a] += r[b];
      p[b] = a;
    }else{
      r[b] += r[a];
      p[a] = b;
    }
    return true;
  }
  return false;
}
bool cmp(edge a, edge b){
  return (a.v > b.v);
}
int main() {
  int n,a,b;

  cin>>n;
  while(n--){
    cin>>a>>b;
    int sum = 0;

    init(a);
    for(int i=0;i<b;i++){
      cin>>D[i].x>>D[i].y>>D[i].v;
      sum += D[i].v;
    }
    //cout<<endl<<sum<<endl;
    sort(D,D+b,cmp);

    for(int i=0;i<b;i++){
      if(joint(D[i].x,D[i].y))
        sum -= D[i].v;
    }
    cout<<sum<<endl;
  }
  cin>>n;
}