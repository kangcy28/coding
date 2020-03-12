#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <time.h>
using namespace std;
string buf[100010],arr[100010];
char table[] = "abcdefghijklnmopqrstuvwxyzABCDEFGHIJKLNMOPQRSTUVWXYZ";

void MergeSort(int L, int R);
void String_Random(int N,int M);

int main()
{
    int N,M;

    srand (time(NULL));
    cin>>N>>M;
    String_Random(N,M);
    MergeSort(0,M);
    for(int i=0; i<M; i++)
        cout<<arr[i]<<endl;
    return 0;
}

void MergeSort(int L, int R)
{
    if(R-L<=1)
        return;
    int M = (R + L) / 2;

    MergeSort(L,M);
    MergeSort(M,R);
    int i = L,j = M,k = L;

    while(i < M|| j<R)
    {
        if(i >= M)
            buf[k] = arr[j++];
        else if(j>=R)
            buf[k] = arr[i++];
        else
        {
            if(arr[i] <= arr[j])
                buf[k] = arr[i++];
            else
            {
                buf[k] = arr[j++];
            }
        }
        k++;
    }
    for(int k=L; k<R; k++)
        arr[k] = buf[k];
}
void String_Random(int N,int M)
{
    for(int i=0; i<N; i++)
    {
        string s = "";

        int String_Length = rand() % M;

        for(int j=0; j<String_Length; j++)
        {
            s += table[rand() % 52];
        }
        arr[i] = s;
    }
}
