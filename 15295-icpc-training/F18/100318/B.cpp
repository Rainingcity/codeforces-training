#include<cstdio>
using namespace std;
const int MOD=998244353;
int n,k;
int dp[1010][3030][2];
int add(int x,int y){
    return (x+y)%MOD;
}
int main(){
    scanf("%d%d", &n, &k);
    dp[1][2][1]=1;dp[1][1][0]=1;
    dp[2][2][1]=3;dp[2][2][0]=3;dp[2][4][1]=1;dp[2][1][0]=1;
    for(int i=1;i<=n;i++) dp[i][1][0]=1;
    for(int i=3;i<=n;i++){
        for(int j=1;j<=k;j++){
            if (j!=1) dp[i][j][0]=add(add(add(dp[i-1][j][1],dp[i-1][j][1]),dp[i-1][j-1][0]),dp[i-1][j][0]);
            dp[i][j][1]=add(add(dp[i-1][j][1],dp[i-1][j-1][0]),dp[i-1][j-1][0]);
            if (j>1) dp[i][j][1]=add(dp[i][j][1],dp[i-1][j-2][1]);
        }
    }
    int ans=add(dp[n][k][0],dp[n][k][1]);
    printf("%d\n", (ans+ans)%MOD);
    return 0;
}
