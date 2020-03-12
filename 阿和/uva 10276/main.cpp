#include <iostream>
#include <cstring>
#include <math.h>
using namespace std;

int main()
{
    int n,m,a[10000];

    cin>>n;
    while(n--){
        cin>>m;
        memset(a,0,sizeof(a));

        int i = 1,index = 1;

        while(index != m + 1){
            int tmp = sqrt(a[index] + i);

            if(tmp * tmp== a[index] + i||a[index]==0){
                a[index] = i;
                index = 1;
                i++;
            }else{
                index++;
            }
        }
        cout<<i-1<<endl;
    }
    return 0;
}
