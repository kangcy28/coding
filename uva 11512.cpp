#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<string>v;
struct lcp
{
	string s;
	int num;
	
	bool operator<(const lcp &rhs)const{
		return s < rhs.s;
	}
};

vector<lcp>vs;
void suffix(string s){
	for(int i=0;i<s.size();i++){
		string str = "";
		for(int j=i;j<s.size();j++){
			str += s[j];
		}
		v.push_back(str);
	}
}
void LCP(){
	for(int i=v.size()-1;i>=1;i--){
		int s1 = 0, s2 = 0, num = 0;
		string str1 = v[i], str2 = v[i-1];
		while(s1 < str1.size() && s2 < str2.size()){
			if(str1[s1] == str2[s2]){
				num++;
			}else{
				break;
			}
			s1++;
			s2++;
		}
		string str = "";
		if(num!=0){
			for(int i=0;i<num;i++){
				str += str2[i];
			}
		}
		if(str == "")continue;
		vs.push_back({str,num});
	}
}

int main(){
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);

	string s;
	int n;

	cin>>n;
	cin>>ws;
	while(n--){
		vs.clear();
		v.clear();
		getline(cin,s);

		suffix(s);
		sort(v.begin(),v.end());
		
		LCP();
		sort(vs.begin(),vs.end());
		
		int tmp=0,a = 0,cnt=0,ans=0;
		string anss = "", s;
		
		for(int i=vs.size()-1;i>=1;i--){
			if(vs[i].s == vs[i+1].s)
				cnt++;
			else
				cnt=1;
			
			if(vs[i].s.size() > anss.size()){
				anss = vs[i].s;
				ans = cnt;
			}else if(cnt > ans){
				ans = cnt;
				anss = vs[i].s;
			}
		}

		for(int i=0;i<vs.size();i++){
			if(vs[i].s.size() > anss.size())
				anss = vs[i].s;
		}
		if(anss.size()!=0)
			cout<<anss<<' '<<ans+1<<endl;
		else
			cout<<"No repetitions found!"<<endl;
		
	}
	return 0;
}