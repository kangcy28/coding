#include <iostream>
#include <math.h>
#define n 100000
bool prime[n],visited[20];
int ans[20],cnt;
using namespace std;
void sieve_prime(){
    for(int i=0;i<n;i++)
        prime[i] = true;
    prime[0] = false;
    prime[1] = false;

    for(int i=2;i<=sqrt(n);i++){
        if(prime[i])
            for(int j = i * i; j < n; j += i){
                prime[j] = false;
            }
    }
}
bool is_prime(int a){
    if(prime[a])
        return true;
    else
        return false;
}

void dfs(int current){
    if(current == cnt){
        if(!is_prime(ans[0]+ans[cnt-1]))
            return;
        for(int i=0;i<cnt;i++){
            if(i==0)
                cout<<ans[i];
            else
                cout<<" "<<ans[i];
        }
        cout<<endl;
    }else{
        for(int i=2;i<=cnt;i++){
            if(!visited[i] && is_prime(i + ans[current - 1])){
                ans[current] = i;
                visited[i] = true;
                dfs(current+1);
                visited[i] = false;
            }
        }
    }
}

int main()
{
    while(cin>>cnt){
        for(int i=0;i<20;i++){
            ans[i] = 0;
            visited[i] = false;
        }
        ans[0] = 1;
        visited[1] = true;
        sieve_prime();
        dfs(1);

    }
    return 0;
}
