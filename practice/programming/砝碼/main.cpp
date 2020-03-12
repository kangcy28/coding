#include <iostream>
#include <cstring>
using namespace std;
int m[201],dp[200001],q[201];
int main()
{
    int n,sum=0,a,b;

    cin>>n;
    while(n--)
    {
        cin>>a>>b;
        memset(dp,0,sizeof(dp));
        for(int i=0; i<a; i++){
            cin>>m[i];
            sum+=m[i];
        }
        for(int i=0; i<b; i++)
        {
            cin>>q[i];
        }

        dp[0]=1;
        dp[sum]=1;
        for(int i=0; i<a; i++)
            for(int j=sum; j>=m[i]; j--)
                if(dp[j-m[i]]==1)
                    dp[j]=1;
        int ans = 0;
        for(int i=0;i<b;i++){
            if(dp[q[i]]==1)
            {
                ans++;
            }
        }
        //for(int i=0;i<=sum;i++)
          //  if(dp[i])
            //    cout<<i<<" ";
        cout<<ans<<endl;
    }
    return 0;
}
