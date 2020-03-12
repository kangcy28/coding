#include <iostream>

using namespace std;
bool a[4][300];
int n,m,step;
bool stepreach = false;

void printstatus(){
    if(step > m){
        stepreach = true;
        return;
    }
    cout << endl; //here
    bool p = false;
    for(int i=1;i<=3;i++){
        cout<<(char)('A' + i-1)<<"=>";
        p = false;
        for(int j=n;j>=1;j--){

            if(a[i][j]){
                if(p==false){
                    cout<<"  ";
                    p = true;
                }
                cout<<" "<<j;
            }
        }
        cout<<endl;
    }
    // cout<<endl;
    step++;
}

void mov(int n, int from, int to){
    a[from][n] = false;
    a[to][n] = true;
    printstatus();
}
void solve(int n, int from ,int middle, int to){
    if(stepreach)return;
    if(n==1){
        mov(1,from,to);
        return;
    }
    else{
        if(step <= m)solve(n-1,from,to,middle);
        if(step <= m)mov(n,from,to);
        if(step <= m)solve(n-1,middle,from,to);
    }
}

int main()
{
    int cnt=1;

    while(cin>>n>>m){
        if(n==0&&m==0)
            break;
        step = 0;


        stepreach = false;
        for(int i=1;i<=3;i++){
            for(int j=1;j<=299;j++){
                a[i][j] = false;
            }
        }
        for(int i=1;i<=n;i++)
            a[1][i] = true;
        // if(cnt!=1)
        //     cout<<endl<<endl;
        cout<<"Problem #"<<cnt<<endl;
        printstatus();
        solve(m,1,2,3);
        cnt++;
        cout << '\n';// here
    }
    return 0;
}
