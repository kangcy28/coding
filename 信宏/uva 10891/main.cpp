#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 105;
int S[maxn], A[maxn], d[maxn][maxn], n, f[maxn][maxn], g[maxn][maxn];

int main()
{
    while(cin>>n){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                f[i][j] = 0;
                g[i][j] = 0;
                d[i][j] = 0;
            }
        }
        if(n==0)
            break;
        S[0] = 0;
        for(int i=1;i<=n;i++){
            cin>>A[i];
            S[i] = S[i-1] + A[i];
        }
        for(int i=1;i<=n;i++)
            f[i][i] = g[i][i] = d[i][i] = A[i];
        for(int len = 1; len<n;len++){
            for(int i=1;i+len<=n;i++){
                int j = i+len;
                int m=0;
                m = min(m, f[i+1][j]);
                m = min(m, g[i][j-1]);
                d[i][j] = S[j] - S[i-1] - m;
                f[i][j] = min(d[i][j], f[i+1][j]);
                g[i][j] = min(d[i][j], g[i][j-1]);
            }
        }
        for(int i=0;i<=n;i++){
            for(int j=0;j<=n;j++){
                cout<<f[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
        for(int i=0;i<=n;i++){
            for(int j=0;j<=n;j++){
                cout<<g[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
        for(int i=0;i<=n;i++){
            for(int j=0;j<=n;j++){
                cout<<d[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
        cout<<2*d[1][n]-S[n]<<endl;
    }
    return 0;
}
