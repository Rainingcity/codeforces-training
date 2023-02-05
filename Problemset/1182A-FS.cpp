/*
 * Codeforces 1182A
 * Filling Shapes
 */

#include <cstdio>
using namespace std;
int n;
int main(){
	scanf("%d", &n);
	if (n&1){
		puts("0");
		return 0;
	}
	printf("%d\n", 1<<(n/2));
	return 0;
}
