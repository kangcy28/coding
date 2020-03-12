#include<bits/stdc++.h>
using namespace std;
const int N = 100000;
const int sqN = sqrt(N);
vector<int>primes;
bool prime[N];
void make(){
	for(int i=0;i<N;i++)
		prime[i] = true;
	prime[0] = false;
	prime[1] = false;
	for(int i=2;i<=sqN;i++){
		if(!prime[i])continue;
		for(int j = i * i; j < N; j += i){
			
			prime[j] = false;
		}
	}
	for(int i=2;i<N;i++)
		if(prime[i])
			primes.push_back(i);
	/*for(auto x : primes)
		cout<<x<<' ';
	*/
}
int main(){
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	make();
	int n;

	while(cin>>n){
		if(n==0)break;
		int ans = 0;
			
		for(int i=0;i<primes.size();i++){
			if(primes[i] >= n/2+1)break;
			int l = primes[i], f = n - l;
			bool flag = false;

			for(int j=i;j<primes.size();j++){
				if(f == primes[j]){
					flag = true;
					break;
				}
			}
			if(flag)ans++;
		}
		cout<<ans<<endl;
	}
}