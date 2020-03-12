#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <math.h>
using namespace std;


struct Point{
	int x,y;
};
vector<Point>P;
vector<Point>ans;
int length(Point a, Point b){
	return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}
bool compare_position(Point a,Point b){
	if(a.y != b.y)return a.y < b.y;
	return a.x < b.x;
}
double cross(Point o, Point  a, Point b){
	return (a.x - o.x) * (b.y - o.y) - (a.y - o.y) * (b.x - o.x);
}
bool compare_angle(Point a,Point b){
	int c = cross(P[0],a,b);
	return c > 0 || (c == 0 && length(P[0],a) < length(P[0],b));
}
double length2(Point a, Point b){
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
int main(){
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);

	int num,n,m,x,y;

	cin>>num;
	while(num--){
		ans.clear();
		P.clear();
		cin>>n>>m;
		for(int i=0;i<m;i++){
			cin>>x>>y;
			P.push_back({x,y});
		}
		//sort(P.begin(), P.end(),compare_position);
		swap(P[0], *min_element(P.begin(), P.end(), compare_position));
		sort(P.begin()+1, P.end(),compare_angle);
		P.push_back({P[0].x,P[0].y});

		for(int i=0;i<P.size();i++){
			int m = ans.size();
			while(m >= 2 && cross(ans[m-2],ans[m-1],P[i]) <= 0)
				ans.pop_back();
			ans.push_back({P[i].x,P[i].y});
		}
		double k = 0;
		for(int i=1;i<ans.size();i++){
			k += length2(ans[i-1],ans[i]);
		}
		//k += length2(ans[ans.size()-1],ans[0]);
		double f = n;
		if(k < f)
			cout<<fixed<<setprecision(5)<<(double)f<<endl;
		else
			cout<<fixed<<setprecision(5)<<k<<endl;
	}
	return 0;
}