#include <iostream>
#include <cstring>

using namespace std;
int coins[200],dp[20010];
int main()
{
    int n,tar;
    memset(dp,0,sizeof(dp));
    cin>>n;
    while(n--)
    {
        int num,p,sum=0;
        cin>>p;
        cin>>num;
        for(int i=0; i<num; i++)
        {
            cin>>coins[i];
            if(sum<p)
            sum+=coins[i];
        }

        for(int i=1; i<=sum; i++)
        {
            dp[i] = num;
        }
        dp[0] = 0;
        for(int i=0; i<num; i++)
        {
            for(int j=sum; j>=coins[i]; --j)
            {
                dp[j] = min(dp[j],dp[j - coins[i]]+1);
            }
        }
        int ans = p;


        while(ans<sum&&dp[ans]==num)
            ans++;
        cout<<ans<<" "<<dp[ans]<<endl;
    }
    return 0;
}
