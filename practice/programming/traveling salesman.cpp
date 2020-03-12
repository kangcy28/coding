#include <iostream>

using namespace std;
int dp[105][105],f[105][105],n,m;
void p(int i,int j){
    if(j!=m+1){
        if(j==1)
            cout<<i;
        else
            cout<<" "<<i;
        p(f[i][j],j+1);
    }

}
int main()
{
    while(cin>>n>>m){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>dp[i][j];
            }
        }
        for(int i=1;i<=n;i++)
            f[i][1]=i;
        for(int i=m-1;i>=1;i--){
            for(int j=1;j<=n;j++){
                int a,b;
                a = j + 1;
                b = j - 1;
                if(a>n)
                    a=1;
                if(b<1)
                    b=n;

                int tmp = dp[j][i+1];
                int to = j;

                if(dp[a][i+1]<tmp||(a<to&&dp[a][i+1]==tmp)){
                    to = a;
                    tmp = dp[a][i+1];
                }
                if(dp[b][i+1]<tmp||(b<to&&dp[b][i+1]==tmp)){
                    to = b;
                    tmp = dp[b][i+1];
                }
                dp[j][i] += tmp;
                f[j][i] = to;
            }
        }
        int e = 1;
        for(int i=1;i<=n;i++)
            if(dp[i][1] < dp[e][1])
                e=i;
        /*for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cout<<dp[i][j]<<" ";
            }
            cout<<endl;
        }*/
        //cout<<e<<" ";
        //int k = f[e][1];
        p(e,1);
        cout<<endl<<dp[e][1]<<endl;
    }
    return 0;
}
