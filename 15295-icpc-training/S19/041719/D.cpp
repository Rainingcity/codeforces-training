#include<cstdio>
#include<cmath>
using namespace std;
int n;
int chk(int x, int n){
	long long cum=x;
	int ans=0;
	while(cum<=n){
		ans++;
		cum*=x;
	}
	return ans;
}
int main(){
	scanf("%d", &n);
	int ans=0;
	int i;
	for(i=2;i*i<=n;i++){
		int k=chk(i,n);
		ans=ans^k;
	}
	if ((n-i+2)&1) ans=ans^1;
	if (ans==0) puts("Petya");
	else puts("Vasya");
	return 0;
}
