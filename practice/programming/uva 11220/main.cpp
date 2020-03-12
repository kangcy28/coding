#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int num,cnt=1;
    cin>>num;
    cin>>ws;
    vector<string>v;
    while(num--){
        string s;
        cout<<"Case"<<" "<<"#"<<cnt<<":"<<endl;
        cnt++;
        while(getline(cin,s)){
            if(s=="")
                break;
            v.clear();
            string str="";
            for(int i=0;i<s.size();i++){
                if(s[i]==' ' && str!=""){
                    v.push_back(str);
                    str="";
                }else{
                    str+=s[i];
                }
            }
            v.push_back(str);

            int k=0;
            string ans="";
            for(int i=0;i<v.size();i++){
                string ss = v[i];
                if(ss.length()-1 >= k){
                    ans+=ss[k];
                    k++;
                }
            }
            cout<<ans<<endl;
        }
    }
    return 0;
}
