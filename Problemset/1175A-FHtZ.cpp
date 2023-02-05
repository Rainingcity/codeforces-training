/*
 * Codeforces 1175A
 * From Hero to Zero
 */

#include <cstdio>
#include <iostream>
using namespace std;
typedef long long ll;
ll n,k;
void solve(){
	cin>>n>>k;
	ll ans = 0;
	while(n){
		ans += n%k;
		if (n>=k) ans += 1;
		n = n/k;
	}
	cout<<ans<<endl;
	return;
}

int main(){
	int T;cin>>T;
	while(T--) solve();
	return 0;
}
