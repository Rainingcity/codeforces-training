#include<cstdio>
using namespace std;
int absi(int x){return x<0?-x:x;}
int maxi(int x,int y){return x<y?y:x;}
int n;
int ax[100100],ay[100100];
int bx[100100],by[100100];
int cx[100100],cy[100100];
int main(){
	scanf("%d", &n);
	for(int i=0;i<n;i++){
		scanf("%d%d", ax+i, ay+i);
	}
	int ans=0;
	for(int i=0;i<n-1;i++){
		bx[i]=absi(ax[i]-ax[i+1]);
		by[i]=absi(ay[i]-ay[i+1]);
		ans+=bx[i]+by[i];
	}
	for(int i=0;i<n-2;i++){
		cx[i]=absi(ax[i]-ax[i+2]);
		cy[i]=absi(ay[i]-ay[i+2]);
	}
	int mx=0;
	for(int i=0;i<n-2;i++){
		mx=maxi(mx,bx[i]+by[i]+bx[i+1]+by[i+1]-cx[i]-cy[i]);
	}
	printf("%d\n", ans-mx);
	return 0;
}
