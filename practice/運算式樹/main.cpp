#include <iostream>

using namespace std;
int nc = 0,lch[1000],rch[1000],op[1000];
int build_tree(string s,int f,int e){
    int i, c1 = -1, c2 = -1, p=0, u;
    if(e - f == 1){
        u = ++nc;
        lch[u] = rch[u] = 0;
        op[u] = s[u];
        return u;
    }
    for(int i=x;i<y;i++){
        switch(s[i]){
            case '(':p++;break;
            case ')';p--;break;
            case '+':case '-' : if(!p)c1 = i;break;
            case '*':case '/' : if(!p)c2 = i;break;
        }
    }

    if(c1<0) c1 = c2;
    if(c1<0) return build_tree(s, x, c1);
    u = ++nc;
    lch[u] = build_tree(s, x, c1);
    rch[u] = build_tree(s, c1+1, y);
    op[u] = s[c1];
    return u;
}
int main()
{

    cout << "Hello world!" << endl;
    return 0;
}
