#include <iostream>
#include <algorithm>
#include <set>
#include <map>
using namespace std;

class vote
{
    friend istream &operator>>(istream& input, vote &);
    friend ostream &operator<<(ostream& output, const vote &);
private:
    string str1;
    string str2;
    string str3;
public:
    vote() {};
    vote (string s1, string s2, string s3): str1(s1), str2(s2), str3(s3){};

    bool operator< (const vote& p2)const
    {
        return str2 > str3;
    }
};

class RuntimeCmp
{
public:
    enum cmp_mode {normal, reverse};
private:
    cmp_mode mode;
public:

    RuntimeCmp (cmp_mode m=normal) : mode(m){}
    template <typename T>
    bool operator() (const T& t1, const T& t2) const {
        return mode==normal ?  t1<t2
                            :  t2<t1;
    }
    // comparison of sorting criteria
    bool operator== (const RuntimeCmp& rc) const {
        return mode == rc.mode;
    }
};

istream& operator>>(istream &input, vote &v)
{
    input>>v.str1;
    input.ignore();
    input>>v.str2;
    input.ignore();
    input>>v.str3;
    return input;
}

ostream& operator<<(ostream &output,const vote &v)
{
    output<<v.str1<<" "<<v.str2<<" "<<v.str3;
    return output;
}
typedef set<vote,RuntimeCmp> Set;
typedef map<Set,int> Map;
int main()
{
    int num_people,num_test;

    cin>>num_test;

    for(int i=0;i<num_test;i++){
        vote v;
        Map M;
        Set s1;
        RuntimeCmp reverse_order(RuntimeCmp::reverse);
        Set s2(reverse_order);

        cin>>num_people;

        for(int i=0; i<num_people; i++)
        {
            cin>>v;

            s1.insert(v);
            s2.insert(v);
            M[s1]++;
        }
        int Max = -1, ans = 0;
        for (auto i : M)
            if (i.second > Max) Max = i.second;
        for (auto i : M)
            if (i.second == Max) ans+=Max;
        cout<<ans<<endl;

        cout<<"Form 1:"<<endl;
        for(auto it :s1)
           cout<<it<<endl;
        cout<<endl;

        cout<<"Form 2:"<<endl;
        for(auto it:s2)
            cout<<it<<endl;
    }
}
