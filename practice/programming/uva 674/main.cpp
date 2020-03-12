#include <iostream>
#include <cstring>
using namespace std;
long long dp[10010];
int coins[5] = {1,5,10,25,50};
void make()
{
    dp[0] = 1;
    for(int i=0; i<=4; i++)
    {
        for(int j=coins[i]; j<=10000; j++)
        {
            dp[j] += dp[j - coins[i]];
        }
    }
}
int main()
{
    int n;


    memset(dp,0,sizeof(dp));
    make();
    while(cin>>n)
    {
        cout<<dp[n]<<endl;
    }
    return 0;
}
