#include <iostream>

using namespace std;
void mergesort(int *A,int x,int y,int *T){
    if(y-x>1){
        int m = x + (y - x) / 2;
        int p = x,q = y,i = m;
        mergesort(A,x,m,T);
        mergesort(A,m,y,T);
        while(p < m || q < y){
            if(q >= y || (p < m && A[p] < A[q])){
                T[i++] = A[p++];
            }else{
                T[i++] = A[q++];
            }
        }
        for(int i=x;i<y;i++)
            A[i] = T[i];
    }
}
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
