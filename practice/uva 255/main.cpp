#include <iostream>
using namespace std;
int maps[9][9];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int check(int k,int q,int t){


    for(int i=0;i<4;i++){
        int ki = k / 8,kj = k % 8;
        int qi = q / 8,qj = q % 8;
        int ti = t / 8,tj = t % 8;
        int x = dx[i], y = dy[i];
        while(qi<8&&qi>=0&&qj<8&&qj>=0&&
                ti<8&&ti>=0&&tj<8&&tj>=0){
            qi += y;
            qj += x;
            if(((qi+y==ki&&qj+x==kj)&&(qi==ti&&qj==tj)))
                return 1;
            else if((qi==ki&&qj==kj))
                return 3;
            if(qi == ti && qj == tj)
                return 2;
        }
    }
    return 0;
}
int main() {
    int k,q,t,po=8;
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            maps[i][j] = po * i + j;
        }
    }
    freopen("in.in",'r',stdin);
    freopen("out.out",'w',stdin);
    while(cin>>k>>q>>t){
        int flag = check(k,q,t);
        if(k==q)
            cout<<"Illegal state"<<endl;
        else if(flag == 1)
            cout<<"Move not allowed"<<endl;
        else if(flag == 0|| flag == 3)
            cout<<"Illegal move"<<endl;
        else if(flag==2&&((t == 9 && k == 0
        )||(t == 49 && k == 56)||(t == 54 && k == 63)||(t == 14 && k == 7))){
            cout<<"Stop";
        }else if(flag == 2){
            cout<<"Continue"<<endl;
        }
    }
}
