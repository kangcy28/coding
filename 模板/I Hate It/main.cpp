#include <iostream>
#include <algorithm>
#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
using namespace std;

int tree[400040],num[200010];
struct node
{
    int l,r,v;
    int mid(){return l+(r-l)/2;}
};
void pushup(int index)
{
    tree[index] = max(tree[index<<1],tree[index<<1|1]);
}
int query(int L, int R, int l, int r, int rt)
{
    if(L <= l && R >= r)
    {
        return tree[rt];
    }
    else
    {
        int mid = l + ((r - l) >> 1);
        int ans1  = -1,ans2 = -1;
        if(L <= mid)
        {
            ans1 = query(L,R,lson);
        }
        if(R > mid)
        {
            ans2 = query(L,R,rson);
        }
        return max(ans1,ans2);
    }
}
void build(int l, int r, int rt)
{
    if(l==r)
    {
        tree[rt] = num[l];
        return;
    }
    int mid = l + ((r - l) >> 1);
    build(lson);
    build(rson);
    pushup(rt);
}
void update(int p,int c,int l,int r,int rt)
{
    if(l==r)
    {
        tree[rt] = c;
    }
    else
    {
        int mid = l + ((r - l)>>1);
        if(p <= mid)
        {
            update(p,c,lson);
        }
        else
        {
            update(p,c,rson);
        }
        pushup(rt);
    }
}
int main()
{

    int n,q;
    while(scanf("%d%d",&n,&q)!=EOF)
    {
        for(int i=1; i<=n; i++)
            scanf("%d",&num[i]);
        getchar();
        build(1,n,1);
        char c;
        int a,b;
        for(int i=0; i<q; i++)
        {
            scanf("%c %d %d",&c,&a,&b);
            getchar();
            if(c == 'Q')
                printf("%d\n",query(a, b, 1, n, 1));
            else if(c == 'U')
                update(a,b,1,n,1);
        }
    }
    return 0;
}

