#include <iostream>
using namespace std;
typedef long long ll;

ll tri(ll x){
	return x*(x+1)/2;
}

int main(){
	ll n;int q;
	cin>>n>>q;
	ll ans;
	if (n==1) ans=1;
	else if (n==2) ans=3;
	else if (n&1) ans=tri((n+3)/2)*2-3-(n+3)/2;
	else ans=tri((n+2)/2)*2-3;
	cout<<ans<<endl;
	for(int i=0;i<q;i++){
		int x;cin>>x;
		if (x==1) cout<<1<<endl;
		else if (x==2) cout<<2<<endl;
		else cout<<(x+3)/2<<endl;
	}
	return 0;
}
