#include<cstdio>
using namespace std;
int a,b,c,d;
int main(){
	scanf("%d%d%d%d", &a, &b, &c, &d);
	printf("%lf\n", (double)a*d/(double(a*d+b*c-a*c)));
	return 0;
}
