#include <iostream>
#include <vector>
using namespace std;

vector<int> v;

int GCD(int a, int b){
    if(b==0)return a;
    v.push_back(a/b);
    return GCD(b,a%b);

}
int main()
{
    int n,a,b;
    cin>>n;
    for(int i=0;i<n;i++){
        v.clear();
        cin>>a>>b;
        GCD(a,b);
        if(a%b==0){
            cout<<a<<"/"<<b<<" = "<<a/b<<endl;
            continue;
        }else{
            cout<<a<<"/"<<b<<" = ";
        }
        for(int j=0;j<v.size();j++){
            cout<<v[j];
            if(j!=v.size()-1&&j!=v.size()-2)
                cout<<"+1/{";
            else if (j== v.size()-2)
                cout<<"+1/";

        }
        for(int k=0;k<v.size()-2;k++)
            cout<<"}";
        cout<<endl;
    }
    return 0;
}
