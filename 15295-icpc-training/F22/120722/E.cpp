#include <iostream>
#include <cmath>
using namespace std;
typedef long long ll;

int X,Y;

void work(){
	cin>>X>>Y;

	ll ans=0;
	int k;
	ll mi=X,mx=0;
	cin>>k;
	for(int i=0;i<k;i++){
		ll x;cin>>x;
		mi=min(x, mi);
		mx=max(x, mx);
	}
	ans=max(ans, (mx-mi)*Y);

	mi=X,mx=0;
	cin>>k;
	for(int i=0;i<k;i++){
		ll x;cin>>x;
		mi=min(x, mi);
		mx=max(x, mx);
	}
	ans=max(ans, (mx-mi)*Y);

	mi=Y,mx=0;
	cin>>k;
	for(int i=0;i<k;i++){
		ll x;cin>>x;
		mi=min(x, mi);
		mx=max(x, mx);
	}
	ans=max(ans, (mx-mi)*X);

	mi=Y,mx=0;
	cin>>k;
	for(int i=0;i<k;i++){
		ll x;cin>>x;
		mi=min(x, mi);
		mx=max(x, mx);
	}
	ans=max(ans, (mx-mi)*X);

	cout<<ans<<endl;
	return;
}

int main(){
	int T;cin>>T;
	while(T--){
		work();
	}
}
