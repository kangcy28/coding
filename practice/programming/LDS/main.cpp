#include <iostream>
using namespace std;
string s;
int length[1000],pre[1000];

void trace(int i)
{
    if (pre[i] != -1) trace(pre[i]);
    cout << s[i];
}

void LIS()
{
    for (int i=0; i<s.size(); i++) length[i] = 1;

    for (int i=0; i<s.size(); i++) pre[i] = -1;

    for (int i=0; i<s.size(); i++)
        for (int j=i+1; j<s.size(); j++)
            if (s[i] > s[j])
                if (length[i] + 1 > length[j])
                {
                    length[j] = length[i] + 1;
                    // s[j] ���b s[i] �᭱
                    pre[j] = i;
                }

    int n = 0, pos = 0;
    for (int i=0; i<s.size(); i++)
        if (length[i] > n)
        {
            n = length[i];
            pos = i;
        }

    trace(pos); // �L�X�@��LIS
}

// ���j����


int main(){
    while(getline(cin,s)){
        LIS();
        cout<<endl;
    }
}
