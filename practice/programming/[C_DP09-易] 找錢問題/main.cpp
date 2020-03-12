#include <iostream>
#include <string.h>
using namespace std;
int coins[4] = {1,5,10,50};
int num[5];
int main()
{
    char ws;
    int t1,t2,t3;

    while(cin>>t1>>ws>>t2>>ws>>t3){
        memset(num,0,sizeof(num));
        int lea = 0;
        if(t2==1)
            lea = t1 - 17 * t3;
        else
            lea = t1 - 25 * t3;
        //cout<<lea<<endl;
        for(int i=3;i>=0;i--){
            if(coins[i] <= lea && lea / coins[i]){
                num[i] = lea / coins[i];
                lea = lea - coins[i] * num[i];
                //cout<<num[i]<<endl;
            }
        }
        int cnt=0;
        for(int i=0;i<4;i++){
            if(num[i]&&!cnt){
                cout<<"Coin "<<coins[i]<<":"<<num[i];
                cnt++;
            }
            else if(num[i])
                cout<<",Coin "<<coins[i]<<":"<<num[i];
        }
        cout<<endl;
    }
    return 0;
}
