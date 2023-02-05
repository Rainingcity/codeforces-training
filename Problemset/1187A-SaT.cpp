/*
 * Codeforces 1187A
 * Stickers and Toys
 */

#include <cstdio>
#include <iostream>
using namespace std;
int maxi(int x, int y){return x<y?y:x;}
int n, s, t;
void run(){
	scanf("%d%d%d", &n, &s, &t);
	int a1 = s+t-n;
	int a2 = s-a1;
	int a3 = t-a1;
	printf("%d\n", maxi(a2, a3)+1);
	return;
}

int main(){
	int T;scanf("%d", &T);
	while(T--){
		run();
	}
	return 0;
}
