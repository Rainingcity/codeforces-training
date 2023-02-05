/*
 * Codeforces 1177B
 * Digital Sequence (Hard Edition)
 */

#include <cstdio>
#include <iostream>
using namespace std;
typedef long long ll;
ll n;
ll dig[11] = {9, 189, 2889, 38889, 488889, 5888889,
		68888889, 788888889, 8888888889ll, 98888888889ll, 1088888888889ll};
ll all_nine(int p){
	ll ans = 1ll;
	for(int i=0;i<p;i++) ans *= 10ll;
	return ans - 1ll;
}
int get_digit(ll pos, ll x){
	while(pos--){
		x/=10ll;
	}
	return (int)(x%10ll);
}
int main(){
	cin>>n;
	int pos=0;
	for(pos=0;pos<11 && dig[pos]<n;pos++);
	if (pos==0){
		cout<<n<<endl;
		return 0;
	}
	ll k = dig[pos]-n;
	ll m = all_nine(pos+1) - k/(ll)(pos+1);
	cout<<get_digit(k%(ll)(pos+1), m)<<endl;
	return 0;
}
