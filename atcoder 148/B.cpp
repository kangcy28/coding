#include<iostream>
using namespace std;
int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
  	int n;
  	string a,b;
  	
  	while(cin>>n){
      
      string str="";
      cin>>a>>b;
    	for(int i=0;i<n;i++){
        	str += a[i];
          str += b[i];
      }
      cout<<str<<endl;
    }
	return 0;
}