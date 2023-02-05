/*
 * Codeforces 1143B
 * Nirvana
 */

#include <cstdio>
using namespace std;
int maxi(int x, int y){return x<y?y:x;}
int n;
int a[12];
int separate_digits(int x){
	int m=0;
	while(x){
		a[m++]=x%10;
		x/=10;
	}
	return m;
}
int main(){
	scanf("%d", &n);
	int m = separate_digits(n);
	int ans = 1;
	for(int i=0;i<m;i++) ans*=a[i];
	int acc = 1;
	for(int i=1;i<m;i++){
		acc *= 9;
		if (a[i]){
			int cur = acc * (a[i]-1);
			for(int j=i+1;j<m;j++) cur *= a[j];
			ans = maxi(ans, cur);
		}
	}
	if (a[m-1]==1){
		ans = maxi(ans, acc);
	}
	printf("%d\n", ans);
	return 0;
}
