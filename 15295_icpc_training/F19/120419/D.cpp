#include <iostream>
#include <vector>
using namespace	std;
typedef long long ll;
int n;
ll d;
vector<ll> cnt,v;
void solve(){
	cin>>d>>n;
	cnt.resize(d);
	for(int i=0;i<d;i++) cnt[i]=0;
	cnt[0]++;
	ll sum=0;
	for(int i=0;i<n;i++){
		ll x;cin>>x;
		sum=(sum+x)%d;
		cnt[sum]++;
	}
	ll ans=0;
	for(int i=0;i<d;i++){
		ans+=(cnt[i]*(cnt[i]-1))>>1;
	}
	cout<<ans<<endl;
	return;
}

int main(){
	int T;cin>>T;
	while(T--){
		solve();
	}
}
