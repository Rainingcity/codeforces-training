/*
 * Codeforces 1167C
 * News Distribution
 */

#include<cstdio>
using namespace std;
int n,m;
int f[500100];
int fnd(int x){
	if (x==f[x]) return x;
	return (f[x]=fnd(f[x]));
}
void add(int x,int y){
	if (fnd(x)==fnd(y)) return;
	f[fnd(x)]=fnd(y);
}
int cnt[500100];
int main(){
	scanf("%d %d", &n, &m);
	for(int i=0;i<n;i++) f[i]=i;
	for(int i=0;i<m;i++){
		int x, x0;
		scanf("%d", &x);
		if (x==0) continue;
		scanf("%d", &x0);x0--;
		for(int i=1;i<x;i++){
			int y;scanf("%d", &y);y--;
			add(x0, y);
		}
	}
	for(int i=0;i<n;i++){
		cnt[fnd(i)]++;
	}
	printf("%d", cnt[fnd(0)]);
	for(int i=1;i<n;i++){
		printf(" %d", cnt[fnd(i)]);
	}
	puts("");
	return 0;
}
