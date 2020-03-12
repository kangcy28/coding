#include <iostream>
#include <cstring>
#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
using namespace std;
int tree[50000];
void pushup(int index){
    tree[index] = tree[index<<1]+tree[index<<1|1];
}
int query(int L, int R, int l, int r, int rt){
    if(L <= l && R >= r){
        return tree[rt];
    }else{
        int mid = (l + r) >> 1;
        int ans  = 0;
        if(L <= mid){
            ans += query(L,R,lson);
        }
        if(R > mid){
            ans += query(L,R,rson);
        }
        return ans;
    }
}
void build(int l, int r, int rt){
    if(l==r){
        return;
    }
    int mid = (l + r) >> 1;
    build(lson);
    build(rson);
    pushup(rt);
}
void update(int p,int c,int l,int r,int rt){
    if(l==r){
        tree[rt] += c;
    }else{
        int mid = (l + r)>>1;
        if(p <= mid){
            update(p,c,lson);
        }else{
            update(p,c,rson);
        }
        pushup(rt);
    }
}
int main(){
  int t;
  int kase = 0;
  scanf("%d", &t);
  while(t--){
    cout<<"Case "<<++kase<<":"<<endl;
    memset(tree,0,sizeof(tree));
    int n;
    cin>>n;
    build(1,n,1);
    int a,b;
    string s;
    while(getline(cin,s)){
      if(s[0] == 'E')break;
      cin>>a>>b;
      if(s[0] == 'Q')
        cout<<query(a, b, 1, n, 1);
      else if(s[0] == 'S')
        update(a,-b,1,n,1);
      else
        update(a,b,1,n,1);
    }
  }
}

