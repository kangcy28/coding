#include <iostream>

using namespace std;
long long m[50];
int main()
{
    long long n,cnt=1;
    while(cin>>n)
    {
        for(int i=0; i<n; i++)
        {
            cin>>m[i];
        }
        long long tmp=1,ma=0;
        for(int i=0; i<n; i++)
        {
            tmp = 1;
            for(int j=i; j<n; j++)
            {
                tmp*=m[j];
                ma = max(ma,tmp);
            }

        }
        cout<<"Case #"<<cnt<<": The maximum product is "<<ma<<"."<<endl<<endl;
        cnt++;
    }
    return 0;
}
