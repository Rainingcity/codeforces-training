#include<cstdio>
#include<cstring>
using namespace std;
int n,k;
int gcd(int x,int y){
	if (y==0) return x;
	return gcd(y,x%y);
}
int main(){
	scanf("%d%d", &n, &k);
	for(int i=0;i<n && k!=1;i++){
		int c;scanf("%d", &c);
		int d=gcd(c,k);
		int t=gcd(d,k/d);
		while(t!=1){
			d=d/t;
			t=gcd(d,k/d);
		}
		k/=d;
	}
	if (k==1) puts("Yes");
	else puts("No");
	return 0;
}
