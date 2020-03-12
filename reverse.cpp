#include <iostream>
using namespace std;
int Reverse(int num){
	int mask = 1;
	int ans = 0;
	for(int i=0;i<8;i++){

		int tmp = 0;
		tmp = num & mask;
		ans |= tmp << (15-2*i);
		//cout<<mask<<' '<<ans<<endl;
		mask <<= 1;
	}
	
	for(int i=1;i<=8;i++){
		int tmp =0;
		tmp = num & mask;
		ans |= tmp >> (i*2-1);
		mask <<= 1;
	}
	return ans;
}
int num[16];
int left_rotate(int n){
	int k = 1;
	num[0] = n % 1;
	for(int i=1;i<=15;i++){
		if(k % (1<<i))
		num[i] = k % (1<< i);

	}
	int tmp = num[15];
	for(int i=1;i<=15;i++){
		num[i] = num[i-1];
	num[0] = tmp;
	int u = 1;
	int ans = 0;
	for(int i=0;i<=15;i++)
		ans += (i<<num[i]);
	
	for(int i=15;i>=0;i--)
		cout<<num[i];
	
	return ans;
}
int main(){
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int n;
	int cnt=0;
	//while(cin>>n){
		n = 1<<15;
		n = Reverse(n);
		cout<<n<<endl;
		
		n = Reverse(n);
		cout<<n<<endl;
		/*cout<<"Case "<<++cnt<<endl; 
		for(int i=1;i<=2;i++){
			n = left_rotate(n);
			cout<<n<<endl;
		}*/
	//}
}
//0000 0000 0000 1010
//0101 0000 0000 0000

//2^14+2^12