/*
 * Codeforces 1174A
 * Ehab Fails to Be Thanos
 */

#include <cstdio>
#include <algorithm>
using namespace std;
int n;
int dat[2010];
int main(){
	scanf("%d", &n);
	for(int i=0;i<2*n;i++) scanf("%d", dat+i);
	sort(dat, dat+2*n);
	bool F=0;
	for(int i=1;i<2*n && !F;i++) if (dat[i]!=dat[i-1]) F=1;
	if (F){
		printf("%d", dat[0]);
		for(int i=1;i<2*n;i++) printf(" %d", dat[i]);
		puts("");
	}else puts("-1");
	return 0;
}
