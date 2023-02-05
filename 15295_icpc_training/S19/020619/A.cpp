#include<cstdio>
#include<cmath>
#include<vector>
using namespace std;
int n,m;
double a[200];
int ed[20000][2];
double edl[20000];
int main(){
	scanf("%d", &n);
	while(n!=0){
		a[0]=0;
		for(int i=1;i<n;i++){a[i]=-1000;}
		scanf("%d", &m);
		for(int i=0;i<m;i++){
			int x,y,z;scanf("%d%d%d", &x, &y, &z);
			x--;y--;
			ed[i][0]=x;ed[i][1]=y;
			edl[i]=log(z/100.0);
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				int x=ed[j][0],y=ed[j][1];
				if (a[x]+edl[j]>a[y]) a[y]=a[x]+edl[j];
				if (a[y]+edl[j]>a[x]) a[x]=a[y]+edl[j];
			}
		}
		printf("%lf\n", exp(a[n-1])*100);
		scanf("%d", &n);
	}return 0;
}