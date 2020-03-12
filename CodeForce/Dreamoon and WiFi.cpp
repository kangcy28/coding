#include <bits/stdc++.h>
using namespace std;
double step(int n){
	double sum = 1;
	for(int i=1;i<=n;i++)
		sum *= i;
	return sum;
}
double x(int a,int b){
	return step(a)/step(b)/step(a-b);
}
int main(){
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	string a,b;
	getline(cin,a);
	getline(cin,b);
	int q = 0,a1=0,a0=0,b1=0,b0=0;
	for(int i=0;i<a.size();i++){
		if(a[i]=='+')
			a1++;
	}
	for(int i=0;i<b.size();i++){
		if(b[i]=='+')
			a1--;
		else if(b[i]=='?')
			q++;
	}
	if(q != 0 && q < a1)
		printf("%.12lf\n",(double)0);
	else if(a1 == 0 && q==0)
		printf("%.12lf\n",(double)1);
	else{
		double sum = 1;
		for(int i=0;i<q;i++)
			sum *= 2;
		printf("%.12lf\n", x(a1,q)/sum);
	}
	return 0;
}