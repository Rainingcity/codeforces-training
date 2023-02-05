#include<cstdio>
using namespace std;
const int MOD = 1e9+7;
typedef long long ll;

ll fastpow (ll x, ll y){
	if (y==0) return 1;
	if (y==1) return x;
	ll k = fastpow (x, y>>1);
	k = (k*k)%MOD;
	if (y&1) return (k*x)%MOD;
	else return k;
}

int n;
int main(){
	scanf("%d", &n);
	printf("%I64d\n", (fastpow(27ll, n)-fastpow(7ll, n)+MOD)%MOD);
	return 0;
}