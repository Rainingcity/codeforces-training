#include <iostream>
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;
void exgcd(ll a,ll b,ll& d,ll& x,ll& y){
	if(!b) { d = a; x = 1; y = 0; }
	else{ exgcd(b, a%b, d, y, x); y -= x*(a/b); }
}
ll inv(ll a, ll p){
	ll d,x,y;
	exgcd(a,p,d,x,y);
	return d == 1 ? (x+p)%p : -1;
}
ll C(ll n, ll m){
	ll ans=1;
	for(int i=0;i<m;i++){
		ans=(ans*(n-i))%MOD;
		ans=(ans*inv(i+1,MOD))%MOD;
	}
	return ans;
}
ll n,m;
int main(){
	cin>>n>>m;
	cout<<C(n+m-1,m-1)<<endl;
	return 0;
}
