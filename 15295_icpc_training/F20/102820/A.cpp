#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;
int n,m;
vector<ll> p{};
vector<ll> f{};
vector<vector<ll>> c{};
int main(){
	cin>>n>>m;
	f.resize(20000);
	c.resize(n+m);
	for(int i=2;i<20000;i++){
		if (!f[i]){
			p.push_back(i);
			f[i]=i;
		}
		for(int j=0;j<p.size();j++){
			if (i*p[j]>=20000) break;
			f[i*p[j]]=p[j];
			if (i%p[j]==0) break;
		}
	}
	c[0].push_back(1);
	c[1].push_back(1);c[1].push_back(1);
	for(int i=0;i<n+m;i++){
		c[i].push_back(1);
		for(int j=1;j<i;j++){
			c[i].push_back((c[i-1][j-1]+c[i-1][j])%MOD);
		}
		c[i].push_back(1);
	}
	ll ans=1;
	for(int i=2;i<=n;i++){
		int tmp=i/f[i], cur=f[i], alpha=1;
		ll prod=1;
		while(tmp!=1){
			if (f[tmp]!=cur){
				prod=(prod*c[m+alpha-1][alpha])%MOD;
				cur=f[tmp];
				alpha=1;
			}else alpha++;
			tmp=tmp/f[tmp];
		}
		prod=(prod*c[m+alpha-1][alpha])%MOD;
		ans=(ans+prod)%MOD;
	}
	cout<<ans<<endl;
	return 0;
}
