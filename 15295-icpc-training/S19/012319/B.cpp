#include<cstdio>
#include<cstring>
using namespace std;
int mini(int x,int y){return x<y?x:y;}
int n,m;
int c[110];
int dp[100100];
int main(){
	scanf("%d%d", &n, &m);
	for(int i=0;i<m;i++) scanf("%d", c+i);
	memset(dp,0x3f,sizeof(dp));
	dp[0]=0;
	for(int i=1;i<=n;i++){
		for(int j=0;j<m;j++){
			if (c[j]<=i){
				dp[i]=mini(dp[i],dp[i-c[j]]+1);
			}
		}
	}
	printf("%d\n", dp[n]);
	return 0;
}