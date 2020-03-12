#include <bits/stdc++.h>
#define INF 10000000
using namespace std;
int speed[6],elevator[6],w[105][105],floors[105],num=0;

void build(int num){
    for(int i=0;i<num;i++){
        for(int j=i+1;j<num;j++){
            int dis = abs(floors[j] - floors[i]) * speed[num];

            if(w[floors[i]][floors[j]] > dis){
                w[floors[i]][floors[j]] = w[floors[j]][floors[i]] = dis;
            }
        }
    }
}

int main()
{
    int num_e,end_floor;

    while(cin>>num_e>>end_floor){
        memset(w,INF,sizeof(w));
        for(int i=0;i<num_e;i++){
            cin>>speed[i];
        }
        num=0;
        for(int i=0;i<num_e;i++){
            while(true){
                cin>>floors[num++];
                if(getchar()=='\n')
                    break;
            }
            build(i);
        }
    }
    return 0;
}
