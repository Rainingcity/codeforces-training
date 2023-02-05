#include <iostream>
using namespace std;
const int MOD=1e9+7;
int n,a,b,k;
int dp[5010][2];
int main(){
	cin>>n>>a>>b>>k;
	if (a<b){
		a=b-a-1;
		n=b-1;
	}else if (a>b){
		a=a-b-1;
		n=n-b;
	}
	for(int i=0;i<n;i++) dp[i][0]=1;
	for(int j=1;j<=k;j++){
		bool nxt=j&1;
		bool prev=!nxt;
		int cur=dp[0][prev];
		for(int i=0,t=0;i<n;i++,t+=2){
			if (i && t<=n) cur=(((cur+dp[t][prev])%MOD)+dp[t-1][prev])%MOD;
			dp[i][nxt]=(cur+MOD-dp[i][prev])%MOD;
		}
	}
	cout<<dp[a][k&1]<<endl;
	return 0;
}
