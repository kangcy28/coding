#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
const int maxn = 510;
int prime[maxn];
typedef  int Matrix[maxn][maxn];
vector<int>v;
void sieve(){
    for(int i=0;i<maxn;i++)
        prime[i] = true;
    prime[0] = false;
    prime[1] = false;
    for(int i=2;i<=sqrt(maxn+0.5);i++){
        if(!prime[i])continue;
        for(int j=i*i;j<maxn;j+=i)
            prime[j] = false;
    }
    for(int i=0;i<maxn;i++)
        if(prime[i])v.push_back(i);
}

int rk(Matrix A,int m,int n){
    int i=0,j=0,r;

    while(i<m && j<n){
        r = i;
        for(int k=i;k<m;k++)
            if(A[k][j]){
                r = k;
                break;
            }
        if(A[r][j]){//有1
            if(r!=i){//不在現在的位置
                for(int k=0;k<=n;k++)
                    swap(A[r][k],A[i][k]);
            }
            for(int u=i+1;u<m;u++){//跟下面的做XOR
                if(A[u][j])
                    for(int j=i;j<=n;j++)A[u][j] ^= A[i][j];

            }
            i++;
        }
        j++;
    }
    return i;
}

int main() {
    int T,maxp=0;
    long long k,n;

    cin>>T;
    sieve();
    int m = v.size();
    while(T--){
        cin>>k;
        Matrix A = {0};
        for(int i=0;i<k;i++){
            cin>>n;
            for(int j=0;j<m;j++){
                while(n % v[j] == 0){
                    maxp = max(v[j],maxp);
                    n /= v[j];
                    A[j][i] ^= 1;
                }
            }
        }
        int r = rk(A,maxp+1,k);
        cout<<(long long)(1<<(k-r))-1<<endl;
    }
}
