#include<cstdio>
using namespace std;
const int BIG=1000000007;
int r,g;
int dp[300050][2];
int maxi(int x,int y){
    return (x<y?y:x);
}
int main(){
    scanf("%d%d", &r, &g);
    if (r>g){
        int t=r;
        r=g;g=t;
    }
    int h;
    for(h=1;h<10000 && h*(h+1)<=(r+g)*2;h++);h--;
    int rmax=r;
    int rmin=maxi(((h*(h+1))>>1)-g,0);
    dp[0][0]=dp[0][1]=1;
    for(int j=1;j<=h;j++){
        int t=j&1;
        for(int i=1;i<=rmax;i++){
            dp[i][t]=dp[i][t^1];
            if (i>=j) dp[i][t]=(dp[i][t^1]+dp[i-j][t^1])%BIG;
        }
    }
    int p=h&1;
    int ans=dp[rmin][p];
    for(int i=rmin+1;i<=rmax;i++){
        ans=(ans+dp[i][p])%BIG;
    }printf("%d\n", ans);
    return 0;
}
