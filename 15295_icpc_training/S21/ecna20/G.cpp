#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
int n,m;
vector<int> v;
vector<int> w;
void SWAP(int& x, int& y){
	x^=y;
	y^=x;
	x^=y;
}
void SWITCH(int x, int y){
	SWAP(w[v[x]], w[v[y]]);
	SWAP(v[x], v[y]);
}
int main(){
	scanf("%d%d", &n, &m);
	v.resize(n);w.resize(n);
	for(int i=0;i<n;i++) v[i]=w[i]=i;
	char tmp;
	for(int i=0;i<m;i++){
		int x,y;
		scanf("%c", &tmp);
		scanf("%c%d %c%d", &tmp, &x, &tmp, &y);
		x--;y--;
		int px=w[x], py=w[y];
		if (px<=py) continue;
		for(int j=py;j<px;j++){
			SWITCH(j, j+1);
		}
	}
	printf("T%d", v[0]+1);
	for(int i=1;i<n;i++) printf(" T%d", v[i]+1);
	printf("\n");
	return 0;
}
