#include <iostream>
#include <algorithm>
#include <vector>
#include <cctype>
#include <string>
using namespace std;
string s1,s2;

int main()
{
    vector<int>v;
    vector<char>v1;
    while(cin>>s1>>s2){
        int l1 = s1.length(),l2 = s2.length();

        /*for(int i=0;i<=l1-l2;i++){
            string s = "";
            int j = i + l2-1,tmp = i;

            while(tmp<=j){
                s += toupper(s1[tmp]);
                tmp++;
            }
            cout<<s<<endl;
            v.push_back(s);
        }*/

        for(int i=0;i<=l1;i++){
            v1.push_back(toupper(s1[i]));
        }

        string news2="";
        for(int i=0;i<l2;i++){
            news2 += toupper(s2[i]);
        }

        int Acount = count (v1.begin(), v1.end(), 'A');
        int Ccount = count (v1.begin(), v1.end(), 'C');
        int Gcount = count (v1.begin(), v1.end(), 'G');
        int Tcount = count (v1.begin(), v1.end(), 'T');
        //int s2count = count (v.begin(), v.end(), news2);
        cout<<Acount<<" "<<Ccount<<" "<<Gcount<<" "<<Tcount<<endl;

        int cnt=0;
        string news1="";
        for(int i=0;i<l1;i++){
            news1 += toupper(s1[i]);
        }
        for(int i=0;i<=l1-l2;i++){
            string s = news1.substr(i,i+l2);
            if(s.compare(news2)==0){
                v.push_back(i+1);
                cnt++;
            }
        }
        if(cnt!=0){
            for(int i=0;i<v.size();i++){
                cout<<v[i]<<" ";
            }
        }
        cout<<cnt<<endl;
    }
    return 0;
}
