#include <iostream>
using namespace std;
typedef long long ll;
ll n;
ll check(ll k){
	ll t=n;
	ll ret=0;
	while(t>0){
		if (t<k) return ret+t;
		ret+=k;t-=k;
		t-=t/10;
	}
	return ret;
}
int main(){
	cin>>n;
	ll l=1,r=n;
	while(l<r){
		ll mid=(l+r)>>1;
		if ((check(mid)<<1)>=n) r=mid;
		else l=mid+1;
	}
	cout<<r<<endl;
	return 0;
}
