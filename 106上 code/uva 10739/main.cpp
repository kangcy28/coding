#include <iostream>

using namespace std;
int dp[1001][1001];
string s;
int finddp(int i,int j){
    if(dp[i][j]==-1){
        if(i>=j)
            return 0;
        if(s[i]==s[j]){
            dp[i][j] = finddp(i+1,j-1);
        }else{
            dp[i][j] = min(finddp(i,j-1),finddp(i+1,j)) + 1;//finddp(i,j-1) ��i add �� j �]�� �W�@�Ӫ��A �O���finddp(i,j-1) ,i�|�@��,j�h�|�V�e,�M��A�U�@�Bstr[i]�|����str[j];
            dp[i][j] = min(dp[i][j],finddp(i+1,j-1) + 1);
        }
    }
    return dp[i][j];
}
int main()
{
    string ws;
    int n,cnt=1;
    cin>>n;

    getline(cin,ws);
    while(n--){
        getline(cin,s);
        int len=s.length();
        for(int i = 0; i < len; i++){
            for(int j = 0; j < len; j++){
                dp[i][j] = -1;
            }
        }

        cout<<"Case "<<cnt<<": "<<finddp(0,len-1)<<endl;
        /*for(int i=0;i<len;i++){
            for(int j=0;j<len;j++){
                cout<<dp[i][j];
            }
            cout<<endl;
        }*/
        cnt++;
    }
    return 0;
}
