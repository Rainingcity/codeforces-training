#include <iostream>
#include <climits>
#include <vector>
using namespace std;
typedef long long ll;
struct seq{
	int x, y, d;
	ll cnt;
	seq()=default;
	seq(int _x, int _y, int _d){
		x=_x; y=_y; d=_d;
		cnt=(y-x)/d+1ll;
	}
};
int n;
vector<seq> v;
ll count(ll b){
	ll ret=0;
	for(auto& s: v){
		if (b>=s.y) ret+=s.cnt;
		else if (b>=s.x){
			ret+=(b-s.x)/s.d+1ll;
		}
	}
	return ret;
}
void solve(){
	ll l=0, r=INT_MAX;
	while(l<r){
		ll mid=(l+r)>>1;
		if (count(mid)&1ll) r=mid;
		else l=mid+1;
	}
	if (count(l)&1ll) cout<<r<<endl;
	else cout<<-1<<endl;
}
int main(){
	int T;cin>>T;
	while(T--){
		cin>>n;
		v.clear();
		for(int i=0;i<n;i++){
			int x, y, d;cin>>x>>y>>d;
			v.emplace_back(x,y,d);
		}
		solve();
	}
}
