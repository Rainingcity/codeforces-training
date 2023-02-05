/*
 * Codeforces 1174B
 * Ehab Is an Odd Person
 */

#include <cstdio>
#include <algorithm>
using namespace std;
int n;
int dat[100100];
int main(){
	scanf("%d", &n);
	for(int i=0;i<n;i++) scanf("%d", dat+i);
	bool F = dat[0]&1;
	int i;
	for(i=1;i<n;i++) if ((dat[i]&1)!=F) break;
	if (i!=n){
		sort(dat, dat+n);
	}
	printf("%d", dat[0]);
	for(i=1;i<n;i++) printf(" %d", dat[i]);
	puts("");
	return 0;
}
