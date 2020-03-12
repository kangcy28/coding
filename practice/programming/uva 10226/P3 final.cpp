#include <iostream>
#include <algorithm>
#include <set>
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
        return str1 < str2;
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

istream& operator>>(istream &input, grade &g)
{
    input>>g.name;
    input.ignore();
    input>>g.english;
    input.ignore();
    input>>g.math;
    return input;
}

ostream& operator<<(ostream &output,const grade &g)
{
    output<<g.name<<" "<<g.english<<" "<<g.math;
    return output;
}
typedef set<grade,RuntimeCmp> IntSet;
int main()
{
    int n;
    grade g;
    IntSet s;
    RuntimeCmp reverse_order(RuntimeCmp::reverse);
    IntSet s1(reverse_order);

    cin>>n;

    for(int i=0; i<n; i++)
    {
        cin>> g;
        s.insert(g);
        s1.insert(g);
    }

    cout<<"Set A:"<<endl;
    for(auto p :s)
        cout<<p<<endl;
    cout<<endl;

    cout<<"Set B:"<<endl;
    for(auto o:s1)
        cout<<o<<endl;
}
