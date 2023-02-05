#include<cstdio>
#include<cstring>
using namespace std;
int maxi(int x,int y){return x<y?y:x;}
int n,w;
int dp[1010][10100];
int value[1010];
int weight[1010];
int main(){
	scanf("%d%d", &n, &w);
	for(int i=0;i<n;i++) scanf("%d", value+i);
	for(int i=0;i<n;i++) scanf("%d", weight+i);
	memset(dp,0,sizeof(dp));
	for(int i=1;i<=n;i++){
		int tempw=weight[i-1];
		int tempv=value[i-1];
		for(int j=tempw;j<=w;j++){
			dp[i][j]=maxi(dp[i-1][j],dp[i-1][j-tempw]+tempv);
		}
		for(int j=0;j<tempw;j++) dp[i][j]=dp[i-1][j];
	}
	printf("%d\n", dp[n][w]);
	return 0;
}