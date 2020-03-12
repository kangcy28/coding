#include <iostream>
#include <algorithm>
using namespace std;

int n;

struct Point{
    int x,y;

    bool operator<(const Point rhs)const{
        return x < rhs.x;
    }
};
Point point[110];
int y[110],l[110],on[110],on2[110];

int solve(){
    sort(y,y+n);
    sort(point,point+n);
    int q = unique(y,y+n)-y;
    if(q<=2)return n;
    int ans = 0;
    for(int a = 0; a < q; a++){
        for(int b = a + 1; b < q; b++){
            int ymin = y[a],ymax = y[b],k=0;

            for(int i = 0; i < n; i++){
                if(i==0||point[i-1].x != point[i].x){//���p�����u�S����s ���N�~���s�u�W�I���ƶq
                    k++;
                    on[k] = on2[k] = 0;
                    if(k==0)
                        l[k] = 0;
                    else
                        l[k] = l[k-1]+ on2[k-1] - on[k-1];//�p��ϣw���ƶq
                }
                if(point[i].y > ymin && point[i].y < ymax)on[k]++;
                if(point[i].y >= ymin && point[i].y <= ymax)on2[k]++;
            }
            if(k<=2)return n;
            int M = 0;
            for(int j=1;j<=k;j++){//�����
                ans = max(ans,l[j]+on2[j]+M);//�@�Ӥϣw�[�W���䨺����(���䨺�����䪺�����I) �]�N�OM!!!
                M = max(M,on[j]-l[j]);
            }
        }
    }
    return ans;
}
int main()
{
    int cnt=0;

    while(cin>>n){
        if(n==0)break;
        cnt++;
        for(int i=0;i<n;i++){
            cin>>point[i].x>>point[i].y;
            y[i] = point[i].y;
        }
        cout<<"Case "<<cnt<<": "<<solve()<<endl;
    }
    return 0;
}
