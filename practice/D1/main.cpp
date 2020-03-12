#include <iostream>
#include <map>
using namespace std;
int A[51]={0},B[51]={0};
void sq(int n){
    while(n>0){
        A[n]++;
        n/=2;
    }
}
int main()
{
    int n,k,ma=0,tmp;

    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>B[i];
        sq(B[i]);
    }

    for(int i=50;i>=0;i--){
        if(A[i]==k){

        }
    }
    return 0;
}
