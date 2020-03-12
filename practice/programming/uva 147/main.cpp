#include <iostream>
#include <cstring>
#include <cstdio>
#include <iomanip>
using namespace std;
int coins[] = {5,10,20,50,100,200,500,1000,2000,5000,10000};
unsigned long long dp[30005];

void make()
{
    dp[0] = 1;
    for(int i=0; i<11; i++)
    {
        for(int j=coins[i]; j<=30000; j+=5)
        {
            dp[j] += dp[j-coins[i]];
        }
    }
}

int main()
{
    memset(dp,0,sizeof(dp));
    make();
    int a,b;
    while(scanf("%d.%d",&a,&b))
    {

        if(a==0&&b==0)
            break;
        printf("%3d.%02d%17llu\n",a,b,dp[a*100+b]);
    }

    return 0;
}
