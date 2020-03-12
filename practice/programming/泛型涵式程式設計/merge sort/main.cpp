#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <time.h>
#include <algorithm>
#include <vector>
#include <iterator>
using namespace std;
char table[] = "abcdefghijklnmopqrstuvwxyzABCDEFGHIJKLNMOPQRSTUVWXYZ";
//string arr[100010];
vector<string> arr;
void String_Random(int N,int M);

int main()
{
    //int N,M;

    srand (time(NULL));
    //cin>>N>>M;
    istream_iterator<int> N (cin);
    istream_iterator<int> M (cin);

    String_Random(*N,*M);
    sort(arr.begin(),arr.end());
    ostream_iterator<int> out_it (cout,"\n");
    copy(arr.begin(),arr.end(),out_it);
    //copy (*arr, , out_it );
    return 0;
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
        arr.push_back(s);
    }
}
