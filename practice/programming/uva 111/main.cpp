#include <iostream>
#include <string.h>
using namespace std;
int length[21][21],num[21],in[21];

int main()
{
    int n;
    while(cin>>n){
        for(int i=1;i<=n;i++)
            cin>>in[i];
        for(int i=1;i<=n;i++){
            num[in[i]] = i;
        }
        for(int i=0;i<=n;i++){
            length[i][0] = 0;
            length[0][i] = 0;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(num[i-1] == num[j-1])
                    length[i][j] = length[i-1][j-1] + 1;
                else
                    length[i][j] = max(length[i-1][j],length[i][j-1]);
            }
        }
        cout<<length[n][n]<<endl;
    }
    return 0;
}
