#include <iostream>
using namespace  std;
int num[20][20];
int dx[8] = {1,1,0,1};
int dy[8] = {0,1,-1,-1};
int win=-1,x,y;
void solve()
{
    for(int i=0; i<=18; i++)
    {
        for(int j=0; j<=18; j++)
        {
            if(num[i][j]==1)
            {
                //cout<<i<<" "<<j<<endl;
                for(int k=0; k<4; k++)
                {

                    int cnt=1;
                    for(int step=1; step<=5; step++)
                    {
                        int nx = j+dx[k]*step;
                        int ny = i+dy[k]*step;

                        if(num[ny][nx]==1&&nx>=0&&nx<=18&&ny>=0&&ny<=18)
                        {
                            cnt++;
                            //cout<<cnt<<endl;
                        }else{
                            break;
                        }

                    }
                    if(cnt==5&&num[i-dx[k]][y-dy[k]]!=num[i][j])
                    {
                        win = 1;
                        x = j+1;
                        y = i+1;
                        return;
                    }
                }
            }
            else if(num[i][j]==2)
            {

                for(int k=0; k<4; k++)
                {
                    int cnt=1;
                    for(int step=1; step<=5; step++)
                    {
                        int nx = i+dx[k]*step,ny=j+dy[k]*step;
                        if(num[ny][nx]==2&&nx>=0&&nx<=18&&ny>=0&&ny<=18)
                        {
                            cnt++;
                        }else{
                            break;
                        }
                    }
                    if(cnt==5&&num[i-dx[k]][y-dy[k]]!=num[i][j])
                    {
                        win = 2;
                        x = j+1;
                        y = i+1;
                        return;
                    }
                }
            }
        }
    }
}
int main()
{
    int n;

    cin>>n;
    while(n--)
    {
        win = -1;
        for(int i=0; i<=18; i++)
        {
            for(int j=0; j<=18; j++)
            {
                cin>>num[i][j];
            }
        }
        solve();
        if(win!=-1)
        {
            cout<<win<<endl;
            cout<<y<<" "<<x<<endl;
        }
        else
            cout<<"0"<<endl;
    }
}
