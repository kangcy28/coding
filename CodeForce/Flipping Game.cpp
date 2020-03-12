#include <bits/stdc++.h>
using namespace std;
int num[100005];
int main(){
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	int n,input;

	cin>>n;


	for(int i=0;i<n;i++){
		cin>>input;
		if(input==1)
			num[i] = -1;
		else
			num[i] = 1;
	}
	int start=0,maxstart=0,e=0,sum=0,ma=0,mastart=0;

	for(int i=0;i<n;i++){//maximum subsequence
		if(sum + num[i]>=0){
			sum += num[i];
		}else{
			start = i + 1;
			sum = 0;
		}

		if(sum >= ma){
			mastart = start;
			e = i;
		}
		ma = max(ma, sum);
	}
	int cnt = 0;
	for(int i=0;i<n;i++){
		if(i>=mastart && i<=e){
			if(num[i]==1)
				cnt++;
		}else if(num[i]==-1)
			cnt++;
	}
	if(mastart > e)
		cnt--;
	cout<<cnt<<endl;
	return 0;
}