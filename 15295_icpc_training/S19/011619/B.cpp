#include<cstdio>
using namespace std;
typedef long long ll;
int n,m,tar;
int a[3000];
int main(){
	scanf("%d", &n);m=(n<<1)+1;
	int height=0;
	for(int i=0;i<m-1;i++){
		scanf("%d", a+i);
		if (i){
			if (i&1) height+=a[i]-a[i-1];
			else height-=a[i]-a[i-1];
		}
	}
	a[m-1]=a[m-2]+height;
	scanf("%d", &tar);
	int ansx=0, ansy=0;
	height=0;
	int tarh=0;
	for(int i=0;i<m-1 && a[i]<tar;i++){
		if (i){
			if (i&1) height+=a[i]-a[i-1];
			else height-=a[i]-a[i-1];
		}
		if (a[i+1]>=tar){
			if (i&1) tarh=height-(tar-a[i]);
			else tarh=height+(tar-a[i]);
		}
	}
	height=0;
	for(int i=0;i<m-1 && a[i]<tar;i++){
		if (i){
			if (i&1) height+=a[i]-a[i-1];
			else height-=a[i]-a[i-1];
		}
		if (i&1){
			ll flag=((ll)tar-a[i])*((ll)ansy-tarh)-((ll)tar-ansx)*((ll)height-tarh);
			if (flag<0) ansx=a[i],ansy=height;
		}
	}
	if (ansx==0) puts("0");
	else printf("%d\n", (int)(((ll)tar*ansy-(ll)ansx*tarh-1)/(tar-ansx))+1);
	return 0;
}