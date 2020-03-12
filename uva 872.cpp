#include <sstream>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;
vector<int>v;
int indegree[200],k=0;
vector<int>G[200];
queue<int>q;

int main(){
    stringstream s1;
    int N;//代表有幾行
    int i1;//用來存放string轉成int的資料
    while(N--){
      while(!q.empty())q.pop();
      cin.ignore();
      string line;//讀入每行的資料
      
      getline(cin,line);//讀入每行的資料
      s1.clear();//清除緩存
      s1<<line;
          
      while(true){
        s1>>i1;
        v.push_back(i1);
        if(s1.fail()) break;//確認stringstream有正常流出，沒有代表空了
      }
      getline(cin,line);//讀入每行的資料
      s1.clear();//清除緩存
      s1<<line;
      while(true){
        s1>>i1;

        G[i1[0]].push_back(i1[2]);
        indegree[i1[2]]++;
        if(s1.fail()) break;//確認stringstream有正常流出，沒有代表空了
      }
      for(int i=0;i<v.size();i++){
        if(indegree[v[i]]==0)
          q.push(v[i]);
      }

    }
    return 0;
}