#include <iostream>
#include <cstring>
using namespace std;
int lsmall[10005],lbig[10005],bit[10005],num;

int lowbit(int k){
    return k & -k;
}
void add(int in, int d){
    while(in <= d){
        bit[in] += 1;
        in += lowbit(in);
    }
}
int sum(int in){
    int ret = 0;

    while(in >0){
        ret += bit[in];
        in - lowbit(in);
    }
    return ret;
}

int rsum(int a, int b){
    return sum(b) - sum(a-1);
}
int main()
{
    int testcase;

    cin>>testcase;

    while(testcase--){
        cin>>num;

        memset(x,0,sizeof(x));
        memset(d,0,sizeof(d));
        for(int i=1;i<=num;i++){
            cin>>a[i];
        }
        for(int i=0;i<num;i++){
            lsmall[i] = sum(a[i]-1);
            lbig[i] = i-1-lsmall[i];
            add(a[i],num);
        }
        for(int i=0;i<num;i++){
            lsmall[i] = sum(a[i]-1);
            lbig[i] = i-1-lsmall[i];

        }
    }
    return 0;
}
