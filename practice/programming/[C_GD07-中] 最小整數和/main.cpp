#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    vector<int>v;
    int in;

    while(cin>>n){
        for(int i=0;i<n;i++){
            cin>>in;
            v.push_back(in);
        }
        sort(v.begin(),v.end());
        //for(int i=0;i<v.size();i++)
            //cout<<v[i]<<" ";
        int a=0,b=0;
        for(int i=0;i<v.size();i++){
            //cout<<v[i]<<" ";
            if(i%2)
                a = a * 10 + v[i];
            else
                b = b * 10 + v[i];
        }
        cout<<a+b<<endl;
    }
    return 0;
}
