#include <iostream>
#include <algorithm>
using namespace std;
int L,T,n;
struct ant
{
    int dir;
    int tag,po;
    bool operator<(const ant &rhs)const
    {
        return po < rhs.po;
    }
} be[10050],af[10050];
int order[10050];
int main()
{
    int cases;

    cin>>cases;

    for(int i=1; i<=cases; i++)
    {
        cout<<"Case #"<<i<<":"<<endl;
        cin>>L>>T>>n;
        char c;
        for(int j=0; j<n; j++)
        {
            be[j].tag = j;

            cin>>be[j].po>>c;
            if(c=='R')
            {
                be[j].dir = 1;
                af[j].po = be[j].po + T;
                af[j].dir = 1;
            }
            else
            {
                be[j].dir = -1;
                af[j].po = be[j].po - T;
                af[j].dir = -1;
            }
        }
        sort(be,be+n);
        for(int j=0; j<n; j++)
            order[be[j].tag] = j;
        sort(af,af+n);
        for(int j=0; j<n-1; j++)
            if(af[j].po == af[j+1].po)
                af[j].dir = af[j+1].dir = 0;
        for(int j=0; j<n; j++)
        {
            int a = order[j];
            if(af[a].po<0||af[a].po>L)
                cout<<"Fell off"<<endl;
            else
            {
                cout<<af[a].po<<" ";
                if(af[a].dir == -1)
                    cout<<"L"<<endl;
                else if(af[a].dir == 0)
                    cout<<"Turning"<<endl;
                else if(af[a].dir == 1)
                {
                    cout<<"R"<<endl;
                }
            }
        }
        cout<<endl;
    }
    return 0;
}
