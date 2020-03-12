#include <iostream>
#include <cstring>
using namespace std;
long long dp[30001],coins[5] = {1,5,10,25,50};
int main()
{
    int n;

    cin>>n;
    memset(dp,0,sizeof(dp));
    dp[0] = 1;

    for(int i=0;i<5;i++){
        for(int j=coins[i];j<=30000;j++){
            dp[j] = dp[j - coins[i]] +  dp[j];
        }
    }
    int m;
    for(int i=0;i<n;i++){
        cin>>m;
        cout<<dp[m]<<endl;
    }
    return 0;
}
