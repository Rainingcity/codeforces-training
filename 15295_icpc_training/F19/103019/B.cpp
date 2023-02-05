#include <iostream>
using namespace std;
const int MOD=1e8;
int dp[110][110][2];
int n1,n2,k1,k2;
int main(){
    cin>>n1>>n2>>k1>>k2;
    for(int i=0;i<=k1;i++) dp[i][0][0]=1;
    for(int j=1;j<=k2;j++) dp[0][j][1]=1;
    for(int i=1;i<=n1;i++){
        for(int j=1;j<=n2;j++){
            for(int k=1;k<=k1 && i-k>=0;k++){
                dp[i][j][0]=(dp[i][j][0]+dp[i-k][j][1])%MOD;
            }
            for(int k=1;k<=k2 && j-k>=0;k++){
                dp[i][j][1]=(dp[i][j][1]+dp[i][j-k][0])%MOD;
            }
        }
    }
    cout<<(dp[n1][n2][0]+dp[n1][n2][1])%MOD<<endl;
    return 0;
}
