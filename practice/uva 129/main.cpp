#include <iostream>

using namespace std;
int n,m,A[1000];

int dfs(int cur){
    if(cur++ == n){
        int f=1;
        for(int i=0;i<cur;i++){
            if(f)f=0;
            else if(i%64==0)cout<<endl;
            else if(i%4==0)cout<<' ';
            cout<<A[i]+'A';
        }
        cout<<endl;
        cout<<cur<<endl;
        return 0;
    }
    for(int i=0;i<m;i++){
        A[cur] = i;
        bool ok = true;
        for(int j=1; 2*j <= cur+1; j++){
            bool e = true;
            for(int k=0;k<j;k++){
                if(A[cur-k-j] != A[cur-k]){
                    e = false;
                    break;
                }
                if(e){
                    ok = false;
                    break;
                }
            }
            if(!ok)
                break;
        }
        if(ok&&!dfs(cur+1))
            return 0;
    }
    return 1;
}
int main()
{
    while(cin>>n>>m){
        for(int i=0;i<1000;i++)
            A[i]=0;
        dfs(0);
    }
    return 0;
}
