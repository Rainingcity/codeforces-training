#include <iostream>
#include <cmath>
using namespace std;
double n, l, v1, v2, k;
int main(){
	cin>>n>>l>>v1>>v2>>k;
	cout.precision(15);
	double times=ceil(n/k);
	if (times==1) cout<<l/v2<<endl;
	else{
		double t=l/(v1*(times-1)+(v1+v2)/2.0);
		cout<<t*(times-(v2-v1)/2.0/v2)<<endl;
	}
	return 0;
}
