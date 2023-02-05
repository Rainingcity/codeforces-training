#include <iostream>
using namespace std;
typedef long long ll;
int n,T;
ll x;
ll gcd(ll a, ll b){
	if (a<0) return gcd(-a, b);
	if (b<0) return gcd(a, -b);
	if (a==0) return b;
	if (b==0) return a;
	return gcd(b, a%b);
}
int main(){
	cin>>n>>T;
	cin>>x;
	ll y=0;
	for(int i=1;i<n;i++){
		ll t;cin>>t;
		y=gcd(y,t-x);
	}
	while(T--){
		ll t;cin>>t;
		x+=t;
		cout<<gcd(x, y)<<endl;
	}
	return 0;
}
