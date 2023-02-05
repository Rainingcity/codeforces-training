#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
typedef long long ll;
const ll MOD=1e9+7;
int n;
unordered_map<ll,ll> mp;
ll fpow(ll x, ll y, ll MD=MOD){
	if (y<0) return 0;
	if (y==0) return 1;
	if (y==1) return x%MD;
	ll res=fpow(x, y>>1, MD);
	res=(res*res)%MD;
	if (y&1) return (res*x)%MD;
	else return res;
}
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		ll x;cin>>x;
		if (mp.count(x)) mp[x]++;
		else mp.emplace(x, 1);
	}
	bool F=false;
	ll exp1=1;
	for(auto& [p, ex]: mp){
		if (F){
			exp1=(exp1*(ex+1))%(MOD-1);
			continue;
		}
		if (ex&1){
			F=true;
			exp1=(exp1*((ex+1)>>1))%(MOD-1);
		}else exp1=(exp1*(ex+1))%(MOD-1);
	}
	ll ans=1;
	if (F){
		for(auto& [p, ex]: mp){
			ans=(ans*fpow(p, (ex*exp1)%(MOD-1)))%MOD;
		}
	}else{
		for(auto& [p, ex]: mp){
			ans=(ans*fpow(p, ((ex>>1)*exp1)%(MOD-1)))%MOD;
		}
	}
	cout<<ans<<endl;
	return 0;
}
