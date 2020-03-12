#include <iostream>
#include <vector>
#include <algorithm>
#define INF 2e9
using namespace std;
typedef vector<int>vi;

const int N = 100005;

int num[N],shif[N],sn;
struct Node
{
    int l,r,value;
} nodes[4*N];

void st_build(int L, int R, int vertex=1)
{
    nodes[vertex].l = L;
    nodes[vertex].r = R;
    if(L==R)
    {
        nodes[vertex].value = num[L];
        return;
    }
    int mid = (L+R)/2;
    int nL = 2*vertex, nR = 2*vertex+1;

    st_build(L, mid, nL);
    st_build(mid+1, R, nR);

    nodes[vertex].value = min(nodes[nL].value, nodes[nR].value);

}

int query(int l, int r, int x = 1)
{
    if(nodes[x].l >= l && nodes[x].r <= r)
        return nodes[x].value;
    int mid = (nodes[x].l+nodes[x].r) / 2;
    int ans = INF;
    if(l <= mid)
        ans = min(ans, query(l, r, x*2));
    if(r > mid)
        ans = min(ans, query(l, r, x*2+1));

    return ans;
}
void update(int k, int v, int x = 1)
{
    if(nodes[x].l == nodes[x].r){
        nodes[x].value = v;
        return;
    }else{
        int mid = (nodes[x].l + nodes[x].r) / 2;
        if(k<=mid)
            update(k, v, x*2);
        else
            update(k, v, x*2+1);

        nodes[x].value = min(nodes[x*2].value, nodes[x*2+1].value);
    }
}

void handle(string s)
{
    int len = s.size();
    int num = -1;
    sn = 0;
    for (int i = 0; i < len; i++)
    {
        if (s[i] >= '0' && s[i] <= '9')
        {
            if (num == -1)
                num = s[i] - '0';
            else
                num = num * 10 + s[i] - '0';
        }
        else
        {
            if (num != -1)
            {
                shif[sn++] = num;
                num = -1;
            }
        }
    }
    sort(shif, shif + sn);
}

int main()
{
    int u,q;

    cin>>u>>q;
    for(int i=1; i<=u; i++)
        cin>>num[i];
    cin>>ws;
    string s;
    st_build(1,u);
    for(int k=0; k<q; k++)
    {
        getline(cin,s);
        handle(s);

        if(s[0]=='q')
        {
            cout<<query(shif[0],shif[1])<<endl;
        }
        else
        {
            int tmp = num[shif[0]];

            update(shif[sn-1],num[shif[0]]);
            for(int i=1; i<sn; i++)
            {
                update(shif[i-1], num[shif[i]]);
                num[shif[i-1]] = num[shif[i]];
            }
            num[shif[sn-1]] = tmp;
        }
    }
    return 0;
}
