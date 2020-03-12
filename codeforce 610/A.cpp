#include<iostream>
#include<algorithm>
#include<vector>
#include<math.h>
using namespace std;
vector<int>v;
int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int t,a,b,c,d;
    cin>>t;
    while(t--){
    	cin>>a>>b>>c>>d;
    	int r = c + d, l = c - d;
    	if(a < b){
    		swap(a,b);
    	}
    	if(l < a && r )

    	cout<<ans<<endl;
    }
	return 0;
}