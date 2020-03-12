#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;
long long dp[500000],item[55];
int main()
{
    int n,m;
    cin>>n;
    for(int i=0;i<n;i++){
        memset(dp,0,sizeof(dp));
        memset(item,0,sizeof(item));
        int sum=0;

        cin>>m;
        for(int j=0;j<m;j++){
            cin>>item[j];
            dp[item[j]] = item[j];
            sum+=item[j];
        }
        int ma = sum/2;
        for(int j=0;j<m;j++){
            for(int k=ma;k>=item[j];k--){
                dp[k] = max(dp[k],dp[k-item[j]]+item[j]);
            }
        }
        int ans=0;
        for(int j=ma;j>=0;j--)
            if(dp[j]){
                ans = dp[j];
                break;
            }
            //cout<<ma<<endl;
        /*for(int i=0;i<=sum;i++){
            if(dp[i])
                cout<<i<<endl;
        }*/
        //cout<<ans<<" "<<ma<<endl;
        cout<<abs(ans - (sum - ans))<<endl;
    }
    return 0;
}
