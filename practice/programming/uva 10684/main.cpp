#include <iostream>
#include <cstring>
using namespace std;
int dp[110][110],num[110][110];
int main()
{
    int n;


    cin>>n;

    memset(dp,0,sizeof(dp));

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            cin>>num[i][j];
        }
    }
    int ans = 0;

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            dp[i][j] = max(dp[i-1][j]+num[i][j],dp[i][j]);

            ans = max(dp[i][j],ans);
        }

    }
    for(int j=1; j<=n; j++)
    {
        for(int i=1; i<=n; i++)
        {
            dp[i][j] = max(dp[i][j-1]+num[i][j],dp[i][j]);

            ans = max(dp[i][j],ans);
        }

    }

    cout<<ans<<endl;
    return 0;
}
