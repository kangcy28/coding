#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int MarbleNumber[10005],parent[10005],outdegree[10005];
int main()
{
    int n,index;

    while(cin>>n)
    {
        if(n==0)
            break;
        memset(MarbleNumber,0,sizeof(MarbleNumber));
        memset(parent,0,sizeof(parent));
        memset(outdegree,0,sizeof(outdegree));
        int ans = 0;
        for(int k=0; k<n; k++)
        {
            cin>>index;
            cin>>MarbleNumber[index];
            cin>>outdegree[index];
            for(int i=0; i<outdegree[index]; i++)
            {
                int tmp;
                cin>>tmp;
                parent[tmp] = index;
            }
        }
            queue<int>q;
            for(int i=1; i<=n; i++)
            {
                if(outdegree[i]==0){
                    q.push(i);
                }
            }
            while(!q.empty())
            {
                int t = q.front();
                q.pop();
                int p = parent[t];
                if(p==0)
                    break;
                if(MarbleNumber[t]!=1)
                {
                    MarbleNumber[p] += MarbleNumber[t] - 1;
                    ans += abs(MarbleNumber[t]-1);
                    MarbleNumber[t] = 1;
                }
                outdegree[p]--;
                if(outdegree[p]==0)
                    q.push(p);
            }

        cout<<ans<<endl;
    }
    return 0;
}
