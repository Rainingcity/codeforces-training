#include<cstdio>
using namespace std;
int n,p;

int countp(int x,int y){
	int tx = (x+p-1)/p;
	int ty = y/p;
	return ty-tx+1;
}

int main(){
	scanf("%d%d", &n, &p);
	int x,y;
	scanf("%d%d", &x, &y);
	double q0 = (double)countp(x,y)/(y-x+1);
	double prev = q0;
	double ans = 0;
	for(int i=1;i<n;i++){
		scanf("%d%d", &x, &y);
		double qc = (double)countp(x,y)/(y-x+1);
		ans += prev + qc - prev * qc;
		prev = qc;
	}
	ans += prev + q0 - prev * q0;
	printf("%lf\n", ans*2000);
	return 0;
}
