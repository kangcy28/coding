#include <iostream>
#include <math.h>
#include <deque>
#define maxn 100005
using namespace std;
int x[maxn],y[maxn],w[maxn],dist[maxn],d[maxn],total_dist[maxn],total_w[maxn];

int f(int i){
    return d[i] - total_dist[i+1] + dist[+1];
}

int main()
{
    int n,c,p;

    cin>>n;

    for(int i=0;i<n;i++){
        cin>>c>>p;

        for(int j=1;j<=p;j++){
            cin>>x[j]>>y[j]>>w[j];
            dist2o[j] = abs(x[j]) + abs(y[j]);
            total_dist[j] = total_dist[j-1] + abs(x[j]-x[j-1]) + abs(y[j]-y[j-1]);
            total_w[j] = total_w[j] + w[j];
        }
        deque<int>Q;
        Q.push_back(0);

        for(int j=1;j<=p;j++){
            while()
        }
    }
    return 0;
}
