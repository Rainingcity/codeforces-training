#include<cstdio>
using namespace std;
int ax[20],ay[20];
struct vect{
	int x,y;
	vect(){}
	vect(int _x,int _y){
		x=_x;y=_y;
	}
}a[20];
int cross(vect x,vect y){
	return x.x*y.y-x.y*y.x;
}
int dot(vect x,vect y){
	return x.x*y.x+x.y*y.y;
}
int sgn(int x){
	return (x==0?0:(x<0?-1:1));
}
int main(){
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			int x;scanf("%d", &x);x--;
			ax[x]=i;ay[x]=j;
		}
	}
	for(int i=0;i<15;i++){
		a[i]=vect(ax[i+1]-ax[i],ay[i+1]-ay[i]);
	}
	int ans=15;
	for(int i=0;i<13;i++){
		int t1=sgn(cross(a[i],a[i+1]));
		int t2=sgn(cross(a[i+1],a[i+2]));
		int t3=sgn(cross(a[i],a[i+2]));
		if (t1==0 || t2==0 || t3==0) continue;
		if (t1==t2 && t1==t3){
			ans--;
			a[i+1]=a[i];
		}
	}
	printf("%d\n", ans);
	return 0;
}
