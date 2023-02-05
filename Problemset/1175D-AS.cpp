/*
 * Codeforces 1175D
 * Array Splitting
 */

#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
int n,m;
ll dat[300100];
ll ans = 0;
bool cmp(ll x, ll y){return x>y;}
int main(){
	scanf("%d%d", &n, &m);
	for(int i=0;i<n;i++) scanf("%I64d", dat+i);
	for(int i=n-2;i>=0;i--) dat[i] += dat[i+1];
	ans = dat[0];
	sort(dat+1, dat+n, cmp);
	for(int i=1;i<m;i++) ans += dat[i];
	printf("%I64d\n", ans);
	return 0;
}
