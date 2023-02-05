#include <iostream>
#include <cmath>
using namespace std;
typedef long long ll;
int solve(){
	ll n;cin>>n;
	ll st = (ll)ceil(sqrt((double)n/2.0));
	if (st==0) st++;
	for(ll i=st;i*i<=n;i++){
		if (n%i==0) return 1;
	}
	return 0;
}
int main(){
	int C;cin>>C;
	while(C--){
		cout<<solve()<<endl;
	}
	return 0;
}
