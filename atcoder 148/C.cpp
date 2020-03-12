#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
vector<int>v;
int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
  	long long n;

    while(cin>>n){
      long long cnt5 = 0;
      if(n%2!=0)
        cout<<0<<endl;
      else{
        n /= 2;

        for(;n;n/=5){
          cnt5 += n/5;
        }
        cout<<cnt5<<endl;
      }
    }
	return 0;
}