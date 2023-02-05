#include<cstdio>
using namespace std;
typedef long long ll;
const int MOD = 1e9+7;
const int halfMOD = 5e8+3;
int a,b,n;

bool is_excellent (int x, int y, int num){
	while(num!=0){
		if (num%10!=x && num%10!=y) return false;
		num/=10;
	}
	return true;
}

ll inv(int x){
	if (x==1) return 1;
	ll t = MOD/x+1;
	return (t*inv(t*x-MOD))%MOD;
}

int main(){
	scanf("%d%d%d", &a, &b, &n);
	ll cur = 1, cursum = a*n;
	int ans = 0;
	if (is_excellent(a,b,cursum)) ans++;
	if (is_excellent(a,b,b*n)) ans++;
	for(int i=1;i<n;i++){
		cur = (((cur * (n-i+1)) % MOD) * inv((ll)i)) % MOD;
		cursum += b-a;
		if (is_excellent(a,b,cursum)) ans = (ans+cur) % MOD;
	}
	printf("%d\n", ans);
	return 0;
}
