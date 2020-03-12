#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
struct pt{
	double x,y;
	bool operator<(const pt &rhs)const{
		if(x != rhs.x)return x < rhs.x;
		return y < rhs.y;
	}
}p[10000],ch[10000];

double cross(pt o, pt a, pt b){
	return (a.x - o.x)*(b.y - o.y)-(a.y - o.y)*(b.x - o.x);
}
int monotone(int n){
	sort(p,p+n);

	int m = 0;
	for(int i=0;i<n;i++){
		while(m >= 2 && cross(ch[m-2], ch[m-1], p[i]) <= 0)
			m--;
		ch[m++] = p[i];

	}
	
	for(int i=n-1, t=m+1;i>=0;i--){
		while(m >= t && cross(ch[m-2], ch[m-1], p[i]) <= 0)
			m--;
		ch[m++] = p[i];
	}
	return m;
}
double dis(pt a, pt b){
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
int main(){
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int n,m,Case;
	double x,y;
	cin>>Case;
	while(Case--){
		cin>>n>>m;
		
		for(int i=0;i<m;i++){
			cin>>x>>y;
			p[i].x = x;
			p[i].y = y;
		}
		
		int cnt = monotone(m);
		double sum = 0;
		for(int i=0;i<cnt-1;i++){
			sum += dis(ch[i],ch[i+1]);
			
		}
		if(sum > n)
			printf("%.5f\n",sum);
		else
			printf("%.5f\n",(double)n);
	}
	return 0;
}