#include <iostream>
#include <cstring>
using namespace std;
long long dp[101][10];
int main()
{

    //freopen("pd1.in","r",stdin);
    int n,num,day;

    cin>>n;
    while(n--){

        memset(dp,0,sizeof(dp));
        cin>>num>>day;
        dp[1][1] = num;
        int ans = 0;
        for(int i = 2; i <= day; i++){
            for(int j = 1; j <= 5 ; j++){
                if(j==1)
                    dp[i][j] = dp[i-1][3] + dp[i-1][4];
                else
                    dp[i][j] = dp[i-1][j-1];
            }
        }
        for(int i=1;i<=5;i++)
            ans += dp[day][i];
        cout<<ans<<endl;
    }
    return 0;
}
