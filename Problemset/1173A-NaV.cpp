/*
 * Codeforces 1173A
 * Nauuo and Votes
 */

#include <cstdio>
using namespace std;
int main(){
	int x, y, z;
	scanf("%d%d%d", &x, &y, &z);
	int k = (x+z-y)*(x-z-y);
	if (k>0){
		if (x>y) puts("+");
		else puts("-");
	}else if (k<0){
		puts("?");
	}else{
		if (z==0) puts("0");
		else puts("?");
	}
	return 0;
}
