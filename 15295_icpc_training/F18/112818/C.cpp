#include<cstdio>
using namespace std;
int n;
int g[100100],gn=0;
int main(){
	scanf("%d", &n);
	for(int i=0;i<n;i++){
		int x,y;scanf("%d%d", &x, &y);
		while(gn>0 && y<g[gn-1]) gn--;
		g[gn++]=y;
	}
	printf("%d\n", gn);
	return 0;
}
