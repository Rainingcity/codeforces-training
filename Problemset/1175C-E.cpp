/*
 * Codeforces 1175C
 * Electrification
 */

#include <cstdio>
using namespace std;
int n,k;
int dat[200100];
int main(){
	int T;scanf("%d", &T);
	while(T--){
		scanf("%d %d", &n, &k);
		for(int i=0;i<n;i++) scanf("%d", dat+i);
		int mipos = (dat[0]+dat[k])>>1, mi = dat[k]-mipos;
		for(int i=1;i+k<n;i++){
			int cur = (dat[i]+dat[i+k])>>1;
			if (dat[i+k]-cur < mi){
				mi = dat[i+k]-cur;
				mipos = cur;
			}
		}
		printf("%d\n", mipos);
	}
	return 0;
}

