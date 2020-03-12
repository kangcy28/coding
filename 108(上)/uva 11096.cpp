#include<bits/stdc++.h>
using namespace std;
struct lo
{
	double x,y;
	bool operator<(const lo &rhs)const{
		if(x != rhs.x)return x < rhs.x;
		return y < rhs.y;
	}
};
vector<lo>v;
lo k[1005];
double cross(lo o, lo a, lo b){
	return (a.x-o.x)*(b.y-o.y)-(a.y-o.y)*(b.x-o.x);
}

double distance(lo a, lo b){
	return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
}

int main(int argc, char const *argv[])
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int Case,l,n,x,y;

	cin>>Case;
	for(int t=1;t<=Case;t++){

		v.clear();
		cin>>l>>n;
		for(int j=0;j<n;j++){
			cin>>x>>y;
			v.push_back({x,y});
		}
		sort(v.begin(), v.end());
		int index = 0;

		for(int i=0;i<v.size();i++){
			while(index >= 2 && cross(k[index-2], k[index-1], v[i]) <= 0)
				index--;
			k[index++] = v[i];
		}
		
		for(int i=v.size()-1,p=index+1;i>=0;i--){
			while(index >= p && cross(k[index-2], k[index-1], v[i]) <= 0)
				index--;
			k[index++] = v[i];
		}
		double sum = 0;
		for(int i=1;i<index;i++){
			sum += distance(k[i-1],k[i]);
		}
		if(sum >= l)	
			printf("%.5lf\n",sum);
		else
			printf("%.5lf\n",(double)l);
	}
	return 0;
}