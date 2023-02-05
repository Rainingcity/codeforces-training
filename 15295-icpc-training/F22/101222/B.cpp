#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <utility>
#include <cmath>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

const ll MOD = 1e9+7;

int maxi(int x, int y){return x<y?y:x;}
int mini(int x, int y){return x<y?x:y;}

ll fres[1010];

int n;
ll cnt = 1;

ll ext_gcd(ll x, ll y, ll& a, ll& b){
	if (x == 0){
		a = 0;
		b = 1;
		return 1;
	}
	ll g = ext_gcd(y % x, x, a, b);
	ll t = a;
	a = b - (y / x) * a;
	b = t;
	return g;
}

ll inv(ll x, ll y){
	ll a, b;
	ext_gcd(x, y, a, b);
	return (a % MOD + MOD) % MOD;
}

// x >= y
ll C(ll x, ll y){
	if (x == 0 || y == 0) return 1;
	if (y * 2 > x) return C(x, x - y);
	ll res = 1;
	for(ll k = x - y + 1; k <= x; k++){
		res = (res * k) % MOD;
	}
	res = (res * inv(fres[y], MOD)) % MOD;
	return res;
}

void build_factorial(){
	fres[0] = 1;
	for(int i = 1; i <= 1000; i++){
		fres[i] = (fres[i-1] * i) % MOD;
	}
	return;
}

int main(){
	build_factorial();
	cin>>n;
	ll sum = 0;
	for(int i = 0; i < n; i++){
		ll c;cin>>c;
		cnt = (cnt * C(sum + c - 1, c - 1)) % MOD;
		sum += c;
	}
	cout<<cnt<<endl;
	return 0;
}
