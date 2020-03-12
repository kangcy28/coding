#include <iostream>
#include <cstring>
using namespace std;
int M[10000][10000],d[10000],P[10000][10000];
int main()
{
    int n,j=0;

    cin>>n;
    memset(M,100000,sizeof(M));
    for(int i=1;i<=n;i++)
        M[i][i] = 0;

    for(int i=0;i<n;i++)
        cin>>d[i]>>d[i+1];


    for(int diagonal = 1; diagonal <= n - 1; diagonal++){
        for(int i=1;i<=n-diagonal;i++){
            j = i + diagonal;
            for(int k=i;k<=j-1;k++){
                if(M[i][j] > M[i][k]+M[k+1][j]+d[i-1]*d[k]*d[j]){
                    M[i][j] = M[i][k]+M[k+1][j]+d[i-1]*d[k]*d[j];
                    P[i][j] = k;
                }
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout<<M[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<M[1][n]<<endl;
    return 0;
}
