#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>


using namespace std;

typedef long long ll;
#define INF 1000000000

int main(){
	int n;
	while (cin>>n, n){
		map<set<int>,int> m;
		int tmp;
		for (int j = 0; j < n; j++){
			set<int> se;
			for (int i = 0; i < 5; i++){
				cin>>tmp;
				se.insert(tmp);
			}
			m[se] += 1;
		}
		int Max = -1, ans = 0;
		for (auto i : m)
			if (i.second > Max) Max = i.second;
		for (auto i : m)
			if (i.second == Max) ans+=Max;
		cout<<ans<<endl;
	}

}
