#include <bits/stdc++.h>
using namespace std;
int Co(int n){
	int cnt=0;
	while(n > 0){
		cnt++;
		n /= 10;
	}
	return cnt;
}
int main(){
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	int n,cnt=0;

	cin>>n;
	int num = 1;
	while(cnt!=n){
		num++;
		int tmp = num, c = Co(num), sum=0;
		for(int i=0;i<c;i++){
			sum += tmp % 10;
			tmp /= 10;
		}
		if(sum==10)
			cnt++;
	}
	cout<<num<<endl;
	return 0;
}