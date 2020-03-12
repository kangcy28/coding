#include <iostream>
#include <math.h>
using namespace std;
int n;
bool prime[20],vis[20];
bool isprime(){
    for(int i=0;i<=16;i++){
        prime[i] = true;
        vis[i] = false;
    }
    for(int i=2;i<=16;i++){
        for(int j=2;j<=(int)sqrt(i);j++){
            if(i%j==0){
                prime[i] = false;

            }
        }
    }
}
int A[20];

void dfs(int cur){
    if(cur == n && prime[A[0] + A[n-1]]){
        for(int i=0;i<n;i++){
            if(i==0)
                cout<<A[i];
            else
                cout<<" "<<A[i];
        }
        cout<<endl;
    }else{
        for(int i=2;i<=n;i++){
            if(!vis[i] && prime[i + A[cur-1]]){
                vis[i] = true;
                A[cur] = i;
                dfs(cur+1);
                vis[i] = false;
            }
        }
    }
}
int main()
{
    int cnt=0;

    while(cin>>n){
        isprime();
        cout<<"Case "<<++cnt<<":"<<endl;
        A[0] = 1;
        dfs(1);
    }
    return 0;
}
