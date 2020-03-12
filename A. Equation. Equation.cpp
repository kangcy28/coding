#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
const int N = 1000000000;
const int M = sqrt(N) + 1;
bool prime[M];
vector<int>primes;
void make_prime(){
	for(int i=0;i<=M;i++)
		prime[i] = true;
	prime[0] = false;
	prime[1] = false;

	for(int i=2;i<=sqrt(M);i++){
		if(!prime[i])continue;
		for(int j=i*i;j<=M;j+=i){
			prime[j] = false;
		}
	}
	
	for(int i = M + 1;i <= M;i++){
		bool flag = false;
		for(int j=0;j<primes.size();j++){
			if(primes[j] % i == 0){
				flag = true;
				break;
			}
		}
		if(!flag)
			primes.push_back(i);
	}
}
int main(){
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int n;
	make_prime();
	while(cin>>n){
		for(int i=0;i<primes.size();i++){
			int x = primes[i];
			int y = x + n;
			cout<<x<<' '<<y<<endl;
			bool flag = false;
			for(int j=0;j<primes.size();j++){
				if(y == primes[j]){
					flag = true;
					break;
				}else if(primes[j] < y){
					flag = false;
					break;
				}

			}
			if(flag){
				cout<<x<<' '<<y<<endl;
				break;
			}
		}
	}
	return 0;
}