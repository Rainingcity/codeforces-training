#include<cstdio>
using namespace std;
int a[5][5];
int xpos[20];
int ypos[20];
int main(){
	for(int i=0;i<4;i++){
		for(it j=0;j<4;j++){
			scanf("%d", a[i]+j);a[i][j]--;
			xpos[a[i][j]]=i;
			ypos[a[i][j]]=j;
		}
	}
	for(int i=3;i<16;i++){
		
	}
}