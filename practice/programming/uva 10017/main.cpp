#include <iostream>
#include <cstring>
using namespace std;
bool stepsReached;
int LastMove,Disks,steps;
bool a[4][251];

void printStatus()
{
    if(steps>LastMove)
        stepsReached = true;
    else
    {
        for(int i=1; i<=3; i++)
        {
            char p = 'A';

            cout<<char(p+i-1)<<"=>";
            bool printSpace = false;
            for(int j=Disks; j>=1; j--)
            {
                if(a[i][j])
                {
                    if(printSpace == false)
                    {
                        cout<<"  ";
                        printSpace = true;
                    }
                    cout<<" "<<j;
                }
            }
            cout<<endl;
        }
        cout<<endl;
        steps++;
    }
}

void mov(int n,int from,int middle,int to)
{
    a[from][n] = false;
    a[to][n] = true;
    printStatus();
}


void hanoi(int n,int from, int middle, int to)
{
    if(!stepsReached)
    {
        if(n==1)
        {
            mov(n,from,middle,to);
        }
        else
        {
            hanoi(n-1,from,to,middle);
            mov(n,from,middle,to);
            hanoi(n-1,middle,from,to);
        }
    }
}

void init()
{
    for(int i=0; i<=3; i++)
    {
        for(int j=0; j<251; j++)
        {
            a[i][j] = false;
        }
    }
}
int main()
{
    int cases=1;

    while(cin>>Disks>>LastMove)
    {
        if(Disks==0&&LastMove==0)
            break;
        cout<<"Problem #"<<cases++<<"\n\n";
        steps = 0;
        stepsReached = false;
        init();
        for(int i=1; i<=Disks; i++)
            a[1][i] = true;
        printStatus();
        hanoi(Disks,1,2,3);
    }
    return 0;
}
