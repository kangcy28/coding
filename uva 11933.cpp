#include <iostream>
#include <vector>
using namespace std;
vector<long long>v;
int main(){
	long long n;

	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);

	while(cin>>n){
		if(n==0)break;
		v.clear();
		long long k = 1,num = 0;

		while(k << num <= n){
			long long tmp = k << num;
			
			if(n & tmp){
				v.push_back(num);
			}
			num++;
		}
		long long a = 0,b = 0;

		for(long long i=0;i<v.size();i++){
			long long tmp = v[i];
			if(i % 2==0){
				a |= 1 << tmp;
			}else{
				b |= 1 << tmp;
			}
		}
		cout<<a<<' '<<b<<endl;
	}
}