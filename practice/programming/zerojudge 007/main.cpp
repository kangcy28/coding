#include <iostream>
#include <bitset>
#include <vector>
#define maxn 70000
using namespace std;
bitset<maxn> isnp;

void prime(){
    isnp.reset();
    isnp[0] = isnp[1] = 1;
    for(long long  i=2;i<maxn;i++){
        if(isnp[i])continue;
        for(long long  j = i * i ; j < maxn; j += i)
            isnp[j] = 1;
    }
}
int main()
{
    int n;
    prime();
    while(cin>>n){
        if(isnp[n])
            cout<<"非質數"<<endl;
        else
            cout<<"質數"<<endl;
    }
    return 0;
}
