#include<cstdio>
#include<string>
#define MIN(x,y) x<y?x:y
using namespace std;
int n,q;
int ax[10010],ay[10010];
int ansn,ansid[2];
void check(int x,int y){
	int mini=1e9+7;
	for(int i=0;i<n;i++){
		int dx=x-ax[i],dy=y-ay[i];
		mini=MIN(mini,dx*dx+dy*dy);
	}
	for(int i=0;i<n;i++){
		int dx=x-ax[i],dy=y-ay[i];
		if (dx*dx+dy*dy==mini){
			if (ansn==2){
				ansn=3;
				return;
			}
			ansid[ansn++]=i+1;
		}
	}
}
int main(){
	scanf("%d%d", &n, &q);
	for(int i=0;i<n;i++) scanf("%d%d", ax+i, ay+i);
	for(int i=0;i<q;i++){
		int x=0,y=0;
		scanf("%d%d", &x, &y);
		ansn=0;
		ansid[0]=ansid[1]=-1;
		check(x,y);
		if (ansn==1){
			printf("REGION %d\n", ansid[0]);
		}else if (ansn==2){
			printf("LINE %d %d\n", ansid[0], ansid[1]);
		}else puts("POINT");
	}
	return 0;
}