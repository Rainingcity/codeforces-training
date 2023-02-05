#include <iostream>
using namespace std;
const double eps = 1e-8;
double absi(double x){return x<0?-x:x;}
int n;
void solve(){
	int cnt=0;
	for(int i=0;i<n;i++){
		double x;cin>>x;
		if (absi(x-0.5)<eps) cnt++;
	}
	cout<<(((1ll<<cnt)-1ll)<<(n-cnt))<<endl;
}
int main(){
	int T;cin>>T;
	while(T--){
		cin>>n;solve();
	}
	return 0;
}
