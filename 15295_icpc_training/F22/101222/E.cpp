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

int f,w,h;
ll fres[100100];

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
	return (((fres[x] * inv(fres[y], MOD)) % MOD) * inv(fres[x - y], MOD)) % MOD;
}

void build_factorial(){
	fres[0] = 1;
	for(int i = 1; i <= 100000; i++){
		fres[i] = (fres[i-1] * i) % MOD;
	}
	return;
}

int main(){
	build_factorial();
	cin>>f>>w>>h;
	if (f==0){
		cout<<int(w>h)<<endl;
		return 0;
	}else if (w==0){
		cout<<1<<endl;
		return 0;
	}else if (h==0){
		cout<<1<<endl;
		return 0;
	}
	ll cnt1=0;
	for(int i=1;i*(h+1)<=w && i<=f;i++){
		cnt1 = (cnt1 + ((((C(w-i*h-1, i-1) * C(f-1, i-1)) % MOD) * 2) % MOD)) % MOD;
	}
	for(int i=2;i*(h+1)<=w && i-1<=f;i++){
		cnt1 = (cnt1 + ((C(w-i*h-1, i-1) * C(f-1, i-2)) % MOD)) % MOD;
	}
	for(int i=1;i*(h+1)<=w && i+1<=f;i++){
		cnt1 = (cnt1 + ((C(w-i*h-1, i-1) * C(f-1, i)) % MOD)) % MOD;
	}
	ll cnt2=0;
	for(int i=1;i<=w && i<=f;i++){
		cnt2 = (cnt2 + ((((C(w-1, i-1) * C(f-1, i-1)) % MOD) * 2) % MOD)) % MOD;
	}
	for(int i=2;i<=w && i-1<=f;i++){
		cnt2 = (cnt2 + ((C(w-1, i-1) * C(f-1, i-2)) % MOD)) % MOD;
	}
	for(int i=1;i<=w && i+1<=f;i++){
		cnt2 = (cnt2 + ((C(w-1, i-1) * C(f-1, i)) % MOD)) % MOD;
	}
	cout<<(cnt1 * inv(cnt2, MOD)) % MOD<<endl;
}
