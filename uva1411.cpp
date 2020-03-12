#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

struct node
{
	int x,y;	
};

struct edge{
	int from,to;
	double dist;
}
vector<node>B,L;
vector<edge>edges;

double dis(int x1,int y1,int x2,int y2){
	return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
}

int main(){
	int n,x,y;

	while(cin>>n){
		for(int i=0;i<n;i++){
			cin>>x>>y;
			B.push_back({x,y});
		}
		for(int i=0;i<n;i++){
			cin>>x>>y;
			L.push_back({x,y});
		}
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				edges.push_back({i,j,dis(B[i].x,B[j].x,L[i].x,L[j].y)});
			}
		}
	}
	return 0;
}