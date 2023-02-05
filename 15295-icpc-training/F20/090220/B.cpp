#include <iostream>
#include <cstdio>
using namespace std;
double absi(double x){return (x<0?-x:x);}
double a[7];
int main(){
	double sum=0;
	double mx=0;
	for(int i=1;i<7;i++){
		scanf("%lf", a+i);
		sum += a[i]*i;
		if (a[i]>mx) mx=a[i];
	}
	printf("%.3lf\n", absi(sum-3.5)/mx);
	return 0;
}
