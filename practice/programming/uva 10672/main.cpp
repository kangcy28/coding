#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
int parent[10010],marbles[10010],out[10010];
int main()
{
    int n,node,marble,child,num_child,in,sum;

    while(cin>>n){
        if(n==0)
            break;
        sum=0;
        queue<int>q;
        memset(parent,0,sizeof(parent));
        memset(marbles,0,sizeof(marbles));
        for(int i=0;i<=n;i++){
            cin>>node>>marble>>num_child;
            marbles[node] = marble;
            out[node] = num_child;
            for(int j=0;j<num_child;j++){
                cin>>in;
                parent[in] = node;
            }
        }
        for(int i=1;i<=n;i++){
            if(out[i]==0)
                q.push(i);
        }
        while(!q.empty()){
            int k = q.front();q.pop();
            int p = parent[k];
            if(p==1)
                break;
            if(marbles[k] != 1){
                marbles[p] += marbles[k] - 1;
                sum += abs(marbles[k] - 1);
                marbles[k] = 1;
            }
            out[p]--;
            if(out[p]==0)
                q.push(p);
        }
        cout<<sum<<endl;
    }
    return 0;
}
