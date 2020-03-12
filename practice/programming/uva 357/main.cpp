#include <iostream>
#include <cstring>
using namespace std;
long long dp[10010];
int coins[21];
void make()
{
    dp[0] = 1;
    for(int i=1; i<=21; i++)
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

    for(int i=1;i<=21;i++)
        coins[i] = i * i * i;
    memset(dp,0,sizeof(dp));
    make();
    while(cin>>n)
    {
        cout<<dp[n]<<endl;
    }
    return 0;
}
