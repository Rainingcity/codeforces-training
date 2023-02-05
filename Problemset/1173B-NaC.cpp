/*
 * Codeforces 1173B
 * Nauuo and Chess
 */

#include <cstdio>
using namespace std;
int n;
int main(){
	scanf("%d", &n);
	printf("%d\n", n/2+1);
	int x=1,y=1;
	for(int i=0;i<n;i++){
		printf("%d %d\n", x, y);
		if (i&1) y++;
		else x++;
	}
	return 0;
}
