/*
 * Codeforces 1194D
 * 1-2-K Game
 */

#include <cstdio>
using namespace std;
int main(){
	int T;scanf("%d", &T);
	while(T--){
		int n,k;scanf("%d%d", &n, &k);
		if (k%3==0){
			int t=n%(k+1);
			if (t%3==0 && t!=k) puts("Bob");
			else puts("Alice");
		}else{
			if (n%3==0) puts("Bob");
			else puts("Alice");
		}
	}
}
