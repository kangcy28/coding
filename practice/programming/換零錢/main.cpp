#include <iostream>
#include <cstring>
using namespace std;
int coin[6] = {1,5,10,50},way[15010];

int main()
{
    int n;

    memset(way,0,sizeof(way));
    cin>>n;
    way[0] = 1;
    for(int i=0;i<4;i++){
        for(int j=1;j<=15000;j++){
            if(j < coin[i])continue;
            way[j] = way[j] + way[j - coin[i]];
        }
    }
    cout<<way[n]<<endl;
    return 0;
}
