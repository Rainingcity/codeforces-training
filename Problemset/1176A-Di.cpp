/*
 * Codeforces 1176A
 * Divide it!
 */

#include <cstdio>
using namespace std;
typedef long long ll;
int q;
int main(){
	scanf("%d", &q);
	while(q--){
		ll x;scanf("%I64d", &x);
		int ans = 0;
		while(x%5==0){
			x /= 5;
			ans += 3;
		}
		while(x%3==0){
			x /= 3;
			ans += 2;
		}
		while(x%2==0){
			x /= 2;
			ans++;
		}
		if (x==1){
			printf("%d\n", ans);
		}else{
			puts("-1");
		}
	}
	return 0;
}
