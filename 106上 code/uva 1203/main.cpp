#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
struct reg{
    int tag;
    int frequence;
    bool operator<(const reg& rhs)const{
        if(frequence!=rhs.frequence)
            return frequence < rhs.frequence;
        else
            return tag < rhs.tag;
    }
};
vector<reg>r;
int main()
{
    string s;
    int num,fre,tag,frequence;

    while(cin>>s){
        if(s=="#")
            break;
        cin>>tag>>frequence;
        r.push_back({tag,frequence});

    }

    int cnt;
    cin>>cnt;

    int k = r.size(),time = r.size();
    for(int i=2;i<=cnt;i++){
        for(int j=0;j<time;j++){
            r.push_back({r[j].tag,r[j].frequence * i});
        }
    }

    sort(r.begin(),r.end());
    for(int i=0;i<cnt;i++){
        cout<<r[i].tag<<endl;
    }
    return 0;
}
