#include <cstdio>
using namespace std;
int n, H;
struct Cow{
	int h,w,s;
	Cow(){}
	Cow(int _h, int _w, int _s){
		h=_h;w=_w;s=_s;
	}
}a[30];
bool operator< (Cow x, Cow y){
	if (x.s!=y.s) return 
}
int main(){
	scanf("%d", &n, &H);
	for(int i=0;i<n;i++){
		int x,y,z;
		scanf("%d%d%d", &x, &y, &z);
		a[i]=Cow(x,y,z);
	}
	sort(a,a+n);
}