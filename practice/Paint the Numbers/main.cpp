#include <iostream>

using namespace std;
int A[101]={0};
int main()
{
    int n,tmp;

    cin>>n;
    for(int i=0;i<n;i++){
        cin>>tmp;
        A[tmp] = 1;
    }
    int cnt=0;
    for(int i=0;i<101;i++){
        if(A[i]){
            cnt++;
            for(int j=i+1;j<101;j++){
                if(A[j]==1 && j%i==0){
                    A[j]=0;
                }
            }

        }
    }
    cout<<cnt<<endl;
    return 0;
}
