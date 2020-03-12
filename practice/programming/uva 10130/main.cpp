#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int dp[1001];
int w[1001],c[1001],bag[1001];

int main()
{
    int n;

    cin>>n;
    while(n--)
    {
        memset(dp,0,sizeof(dp));
        memset(bag,0,sizeof(bag));

        int num;
        cin>>num;

        for(int i=0; i<num; i++)
        {
            cin>>c[i]>>w[i];
        }


        for(int i = 0; i < num; i++)
        {
            for(int j = 31; j >= w[i]; j--)
            {
                dp[j] = max(dp[j],dp[j - w[i]] + c[i]);
            }
        }

        int bagnum,ans = 0;
        cin>>bagnum;

        for(int i=0; i<bagnum; i++){
            cin>>bag[i];
            ans += dp[bag[i]];
        }
        cout<<ans<<endl;
    }
    return 0;
}
