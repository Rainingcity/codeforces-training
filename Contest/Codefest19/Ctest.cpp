#include <cstdio>
#include <cstring>
using namespace std;
int v[1000][1000];
int p=-1;
int main(){
	freopen("input.txt", "r", stdin);
	int n;scanf("%d", &n);
	for(int i=0;i<n;i++){
		int t=0;
		for(int j=0;j<n;j++){
			scanf("%d", v[i]+j);
			t^=v[i][j];
		}
		printf("%d %d\n", i, t);
		if (p==-1) p=t;
		else if (p!=t){
			puts("FALSE");
			return 0;
		}
	}
	for(int j=0;j<n;j++){
		int t=0;
		for(int i=0;i<n;i++) t^=v[i][j];
		printf("%d %d\n", j, t);
		if (p!=t){
			puts("FALSE");
			return 0;
		}
	}
	puts("TRUE");
	return 0;
}
