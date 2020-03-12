#include <iostream>
using namespace  std;
int num[50050];
int main() {
    int n;

    while(cin>>n){
        for(int i=0;i<n;i++){
            cin>>num[i];
        }
        int f = 0,r = 1;
        int ma;
        while(r != n){
            ma = 0;
            while(num[f] < num[r]){
                ma++;
                r++;
                if(r==n)
                    break;
            }
            ma = max(ma,r - f);
            if(r==n)
                break;
            f = r;
            r++;
        }
        if(ma)
            cout<<ma<<endl;
        else
            cout<<"-1"<<endl;
    }
}
