#include<cstdio>
using namespace std;

int gcd(int x, int y){
	if (y==0) return x;
	return gcd(y, x%y);
}

int main(){
	int T;scanf("%d", &T);
	while(T--){
		int x;scanf("%d", &x);
		int d=gcd(x, 180);
		if (180-x == d){
			printf("%d\n", 360/d);
		}else{
			printf("%d\n", 180/d);
		}
	}
	return 0;
}
