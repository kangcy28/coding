#include <iostream>
#include <cstring>
using namespace std;
int a[30];
int main()
{
    int n;

    while(cin>>n){
        memset(a,0,sizeof(a));
        a[0] = n;
        int ans = 1,index=1;
        while(a[0]!=1){
            if(index==0||a[index]!=1){
                a[index]--;
                a[index+1]++;
                index++;
                ans++;
            }else{
                index--;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
