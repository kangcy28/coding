#include <iostream>
#include <cstring>
using namespace std;
int m[100][100],p[100][100],n;

void path(int q, int r){
    if(p[q][r] != 0){
        path(q, p[q][r]);
        cout<<p[q][r]<<" ";
        path(p[q][r], r);
    }
}
void floy(){
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(m[i][j] > m[i][k] + m[k][j]){
                    m[i][j] = m[i][k] + m[k][j];
                    p[i][j] = k;
                }
            }
        }
    }
}

int main()
{
    memset(m,0,sizeof(m));
    memset(p,0,sizeof(p));
    int a,b;

    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a>>b;
        cin>>m[a][b];
    }
    floy();
    path(1,n);
    return 0;
}
