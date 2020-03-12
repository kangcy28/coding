#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int main()
{
    std::ios::sync_with_stdio(false);
    int pages,numbers;
    string s;
    vector<string>v,ss;
    map<string,int>p;
    while(cin>>pages>>numbers){
        cin>>s;
        v.clear();
        ss.clear();
        for(int i=0;i<s.length();i+=numbers){
            string sub = s.substr(i,numbers);
            v.push_back(sub);
            ss.push_back(sub);
            //cout<<sub<<endl;
        }

        for(int i=0;i<s.length();i++){
            string sk = s.substr(i,1);
            if(!p.count(sk))
                p[sk]=1;
            else
                p[sk]++;
            //string sa ="";
            //sa += s[i];
            //ss.push_back(sa);
        }

        int p,n,N;
        string par;
        while(cin>>p>>n>>N){

            string sss = v[p-1];
            string num = "";

            num += sss[n-1];
            par += sss[n-1];
            //int mycount = ;
            cout<<num<<" "<<p[num]<<" "<<p[num] % N<<endl;
        }
        vector<string>vv;
        for(int i=0;i<par.length();i++){
            string tmp = "";

            tmp += par[i];
            vv.push_back(tmp);
        }
        sort(vv.begin(),vv.end());
        string ns = "";

        for(int i=0;i<par.length();i++)
            ns += vv[i];
        int cnt = 0;

        vector<string>vs;

        for(int i=0;i<s.length() - par.length();i++){
            string sz = s.substr(i,par.length());
            vs.push_back(sz);
        }
        do{
            cnt += count(vs.begin(),vs.end(),ns);
        }while(next_permutation(ns.begin(),ns.end()));
        cout<<par<<" "<<cnt<<endl;
    }
    return 0;
}
