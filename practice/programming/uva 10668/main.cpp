#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;

int main()
{
    double l,C,n;

    while(cin>>l>>C>>n){
        if(l<0&&C<0&&n<0)
            break;
        double R=0.5*l,L=0.0,S = (1+C*n)*l,mid=0;
        while(R-L>1e-6){
            mid = (R+L)/2;
            double r = (l*l+4*mid*mid)/(8*mid);
            double x = 2*r*asin(l/r/2.0);
            if(x<S)
                L = mid;
            else
                R = mid;
        }
        cout<<fixed<<setprecision(3)<<mid<<endl;
    }
    return 0;
}
