#include<cstdio>
using namespace std;
int n;
int a[600];
int dp[600][600];
int mini(int x,int y){
    return (x>y?y:x);
}
int main(){
    scanf("%d", &n);
    for(int i=0;i<n;i++) scanf("%d", a+i);
    for(int c=0;c<n;c++){
        for(int i=0;i<n-c;i++){
            int j=i+c;
            if (c==0){dp[i][j]=1;continue;}
            if (c==1){
                if (a[i]==a[j]) dp[i][j]=1;
                else dp[i][j]=2;
                continue;
            }
            dp[i][j]=10000;
            for(int l=i;l<j;l++){
                dp[i][j]=mini(dp[i][j],dp[i][l]+dp[l+1][j]);
            }
            if (a[i]==a[j]) dp[i][j]=mini(dp[i][j],dp[i+1][j-1]);
        }
    }printf("%d\n", dp[0][n-1]);
    return 0;
}
