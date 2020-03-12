#include <iostream>
#include <cstring>
using namespace std;
int a[100000],b[100000];
int main()
{
    int n,s;

    while(cin>>n>>s){
        a[0] = 0;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        memset(b,0,sizeof(b));
        for(int i=1;i<=n;i++){
            b[i] = b[i-1] + a[i];
        }
        int mi = 100000;
        int i=1;
        for(int j=1;j<=n;j++){
            if(b[j] - b[i] < s)continue;
            while(b[j] - b[i] >= s)i++;
            mi = min(mi,j - i + 1);
        }

        if(mi==100000)
            cout<<0<<endl;
        else
            cout<<mi<<endl;
    }
    return 0;
}
