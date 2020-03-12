#include <iostream>
#include <cstring>

using namespace std;
int dp[501],coins[4] = {1,5,10,50},cnt[501][4],shop[2] = {17,25};
int main()
{
    int types,n,w,num,h;
    char t,s;
    while(cin>>n>>t>>w>>s>>num)
    {
        //memset(dp,100000,sizeof(dp));
        for(int i=0; i<=500; i++)
        {
            dp[i] = 10000000;
            for(int j=0; j<4; j++)
                cnt[i][j] = 0;
        }
        for(int i = 0; i < 4; i++)
        {
            for(int j = 500; j >= coins[i]; j--)
            {
                //cout<<j % coins[i]<<" "<<j / coins[i]<<" "<<dp[j]<<endl;
                if(j % coins[i] == 0 && j / coins[i] < dp[j])
                {
                    dp[j] = cnt[j][i] = j / coins[i];

                    if(i!=0)
                        //cnt[j][i-1] -= coins[i] / coins[i-1];
                        h = coins[i] / coins[i-1];
                        if(h!=0){
                            cnt[j][i-1] -= h * j / coins[i-1];
                            cnt[j][i] = h;
                        }
                }
            }
        }/*
        for(int i=0; i<4; i++)
        {
            for(int j=500; j>=coins[i]; j--)
            {
                if(dp[j] + 1 < dp[j - coins[i]])
                {
                    dp[j - coins[i]] = dp[j] + 1;
                    if(i!=0&&j < coins[i])
                    {
                        int tmp = coins[i] / coins[i-1];
                        cnt[j][i-1] -= tmp * j / coins[i-1];
                        cnt[j][i] = tmp;
                    }
                }
            }
            for(int j=coins[i]; j<=500; j++)
            {
                if(dp[j] + 1 < dp[j + coins[i]])
                {
                    dp[j + coins[i]] = dp[j] + 1;
                    if(i!=0&&j < coins[i])
                    {
                        int tmp = coins[i] / coins[i-1];
                        cnt[j][i-1] -= tmp * j / coins[i-1];
                        cnt[j][i] = tmp;
                    }
                }
            }
        }
        int c = 0;

        n -= shop[w] * num;
        for(int i=0; i<4; i++)
        {
            if(c!=0)
                cout<<",";
            if(cnt[n][i]){
                cout<<"Coin "<<coins[i]<<":"<<cnt[n][i];
                c++;
            }
        }
        cout<<endl;*/
    }
    return 0;
}
