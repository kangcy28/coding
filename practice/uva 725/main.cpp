#include <iostream>
#include <set>
using namespace std;
void solve(int n){
    int tmp;
    set<int>s;
    bool flag = false;
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            for(int k=0;k<10;k++){
                for(int t=0;t<10;t++){
                    for(int y=0;y<10;y++){
                        tmp = i*10000 + j*1000 + k*100 + t*10 + y;
                        int p = tmp * n;
                        if(p < 99999){

                            s.clear();
                            s.insert(i);s.insert(j);s.insert(k);s.insert(t);s.insert(y);
                            if(p<9999)
                                s.insert(0);
                            else
                                s.insert(p / 10000);
                            s.insert(p / 1000 % 10);s.insert(p / 100 % 10);s.insert(p / 10 % 10); s.insert(p % 10);
                            if(s.size()==10){
                                flag = true;
                                /*if(p<9999){
                                    cout<<"0"<<p;
                                }else*/
                                    cout<<p;
                                cout<<" / ";
                                if(tmp<9999){
                                    cout<<"0"<<tmp;
                                }else
                                    cout<<tmp;
                                cout<<" = "<<n<<endl;
                            }
                        }
                    }
                }
            }
        }
    }
    if(!flag)cout<<"There are no solutions for "<<n<<"."<<endl;
}
int main()
{
    int n,cnt = 0;

    while(cin>>n){
        if(cnt)cout<<endl;
        cnt++;
        if(!n)break;
        solve(n);
    }
    return 0;
}
