#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;
int t[101],A[101],B[101],C[11] = {0};

int main()
{
    int n,a,b;
    cin>>n;
    string s;
    cin>>ws;
    getline(cin,s);
    for(int i=0; i<n; i++)
    {
        cin>>A[i]>>B[i];
        t[i] = B[i];
    }
    int ma = 0;
    int f = 0;
    while(f<=125)
    {
        for(int i=0; i<s.size(); i++)
        {
            if(f == t[i])
            {
                if(s[i]=='1')
                    s[i]='0';
                else
                    s[i]='1';
                t[i] += A[i];
            }
        }
        int cnt = 0;
        for(int i=0; i<s.size(); i++)
            if(s[i]=='1')
                cnt++;
        ma = max(ma,cnt);
        f++;
    }
    cout<<ma<<endl;
}
