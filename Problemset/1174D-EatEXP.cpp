/*
 * Codeforces 1174D
 * Ehab and the Expected XOR Problem
 */

#include <cstdio>
using namespace std;
int n,x;
int m;
int ans=0;
int s[300100];
bool f[300100];
int main(){
	scanf("%d%d", &n, &x);
	m = 1<<n;
	if (x>=m) x=0;
	for(int i=1;i<m;i++){
		if (i==x) continue;
		if (f[i]) continue;
		s[ans++]=i;
		f[i]=1;
		f[i^x]=1;
	}
	printf("%d\n", ans);
	if (ans==0) return 0;
	printf("%d", s[0]);
	for(int i=1;i<ans;i++){
		printf(" %d", s[i]^s[i-1]);
	}
	puts("");
	return 0;
}
