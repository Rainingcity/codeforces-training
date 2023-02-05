#include <iostream>
using namespace std;
typedef long long ll;
inline ll mini(ll x, ll y){return x>y?y:x;}
ll n,x,y,c;
ll sq(ll l){
	return l*(l+1)*2+1;
}
ll diatri(ll l){
	return l*(l+1)/2;
}
ll tri(ll l){
	return l*l;
}
ll check(ll sc){
	ll ans=sq(sc);
	if (x<sc) ans-=tri(sc-x);
	if (y<sc) ans-=tri(sc-y);
	if (n-x<=sc) ans-=tri(sc-n+x+1);
	if (n-y<=sc) ans-=tri(sc-n+y+1);
	if (x+y+1<sc) ans+=diatri(sc-x-y-1);
	if (x+n-y<sc) ans+=diatri(sc-x-n+y);
	if (y+n-x<sc) ans+=diatri(sc-y-n+x);
	if (n-x+n-y-1<sc) ans+=diatri(sc+x+y-n-n+1);
	// cout<<ans<<endl;
	return ans;
}
int main(){
	cin>>n>>x>>y>>c;
	x--;y--;
	if (c==1){
		cout<<0<<endl;
		return 0;
	}
	ll l=1,r=mini(2*n,1000000);
	while(l<r){
		ll mid=(l+r)>>1;
		// cout<<mid<<" ";
		if (check(mid)>=c) r=mid;
		else l=mid+1;
	}
	cout<<r<<endl;
	return 0;
}
