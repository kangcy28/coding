#include <iostream>
#include <map>
#include <iomanip>

using namespace std;

int main()
{

    int n,cnt=0;
    string s,ws;

    cin>>n;

    getline(cin,ws);
    getline(cin,ws);
    map<string,double> p;
    for(int i=0; i<n; i++)
    {
        int cnt = 0;
        p.clear();
        while(!cin.eof())
        {
            getline(cin,s);
            if(s[0]=='\0')
            {
                break;
            }

            cnt++;
            if(!p.count(s))
            {
                p[s]=1;
            }
            else
            {
                p[s]++;
            }
        }
        if(i>0)
            cout<<endl;
        for(auto& it : p)
        {
            cout<<it.first<<" "<<fixed<<setprecision(4)<<100*it.second/cnt<<endl;
        }
    }
    return 0;
}
