#include<cstdio>
#include<cmath>
using namespace std;
const double pi = 3.14159265359;
typedef long long ll;
typedef long double ld;
int a1, b1, r1;
int a2, b2, r2;
void swap(int &x, int &y){
	x=x^y;y=x^y;x=x^y;
}

ll calcdistsq(){
	return ((ll)a1-a2)*(a1-a2)+((ll)b1-b2)*(b1-b2);
}

int main(){
	scanf("%d%d%d%d%d%d", &a1, &b1, &r1, &a2, &b2, &r2);
	if (r1<r2){
		swap(a1, a2);swap(b1, b2);swap(r1, r2);
	}
//	printf("%d\n", r1);
	ll dsq = calcdistsq();
	ll minussq = ((ll)r1-r2)*(r1-r2);
	ll plussq  = ((ll)r1+r2)*(r1+r2);
	if (dsq >= plussq){
		puts("0.000000");
		return 0;
	}
	if (dsq <= minussq){
		printf("%lf\n", pi*r2*r2);
		return 0;
	}
//	printf("%ld %ld %ld\n", plussq, minussq, dsq);
	if (dsq <= (ll)r1*r1-(ll)r2*r2){
		ld poly_area = sqrt((ld)dsq-minussq)*sqrt((ld)plussq-dsq)/2.0000;
		ld cir1_area = asin(poly_area/sqrt((ld)dsq)/r1)*(ld)r1*(ld)r1;
		ld cir2_area = (pi-asin(poly_area/sqrt((ld)dsq)/r2))*(ld)r2*(ld)r2;
//		printf("%lf %lf %lf\n", cir1_area, cir2_area, poly_area);
		printf("%lf\n", (double)(cir1_area+cir2_area-poly_area));
	}else{
		ld poly_area = sqrt((ld)(dsq-minussq))*sqrt((ld)(plussq-dsq))/2.0000;
		ld cir1_area = asin(poly_area/sqrt((ld)dsq)/r1)*(ld)r1*(ld)r1;
		ld cir2_area = asin(poly_area/sqrt((ld)dsq)/r2)*(ld)r2*(ld)r2;
//		printf("%lf %lf %lf\n", cir1_area, cir2_area, poly_area);
		printf("%lf\n", (double)(cir1_area+cir2_area-poly_area));
	}
	return 0;
}
