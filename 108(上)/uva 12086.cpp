#include<bits/stdc++.h>
using namespace std;
long long bit[200001], n;
vector<long long>v;
long long Lowbit(long long n){
	return n & (-n);
}

long long sum(long long k){
	long long sum = 0;//cout<<sum<<' '<<k<<endl;
	while(k>=1){
		sum += bit[k];
		k -= Lowbit(k);

	}
	return sum;
}

long long rsq(long long l,long long r){
	if(l == 1)
		return sum(r);
	return sum(r) - sum(l-1);
}
void init(){
	for(long long i=1;i<=n;i++){
		long long index = i;
		bit[index] += v[i-1];
		//cout<<index<<' '<<v[i]<<endl;
		index += Lowbit(index);
		while(index <= n){
			bit[index] += v[i-1];
			index += Lowbit(index);
		}
	}
}
void change(long long index, long long k){
	long long dif = k - v[index-1];

	v[index-1] = k;;
	while(index <= n){
		bit[index] += dif;
		index += Lowbit(index);
	}
}
int main(){
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	long long cnt = 1;
	while(cin>>n){
		if(n==0)
			break;
		if(cnt!=1)cout<<endl;
		cout<<"Case "<<cnt<<":"<<endl;
		cnt++;
		memset(bit,0,sizeof(bit));
		v.clear();
		
		long long tmp;
		for(long long i=1;i<=n;i++){
			cin>>tmp;
			v.push_back(tmp);
		}
		init();
		
		string s;
		while(cin>>s){
			if(s=="END")break;
			if(s=="M"){
				long long l,r;
				cin>>l>>r;
				cout<<rsq(l,r)<<endl;
			}else if(s=="S"){
				long long index,num;

				cin>>index>>num;
				change(index,num);
			}
			/*for(long long i=1;i<=n;i++)
				cout<<bit[i]<<' ';
			cout<<endl;*/
		}
	}
	return 0;
}