/*
 * Codeforces 1169A
 * Circle Metro
 */

#include<cstdio>
using namespace std;
int n,a,x,b,y;
int main(){
	scanf("%d%d%d%d%d", &n, &a, &x, &b, &y);
	a--;x--;b--;y--;
	int i=a,j=b;
	bool F=0;
	while(i!=x && j!=y){
		if (i==j) F=1;
		i=(i+1)%n;
		j=(j+n-1)%n;
	}
	if (i==j) F=1;
	if (F) puts("YES"); else puts("NO");
	return 0;
}
