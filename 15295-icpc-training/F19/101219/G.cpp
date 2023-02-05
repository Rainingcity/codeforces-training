#include <iostream>
using namespace std;
typedef long long ll;
ll mini(ll x, ll y){return x<y?x:y;}
ll maxi(ll x, ll y){return x<y?y:x;}
int n,m;
ll dat[110];
ll dp[110][20010];
int main(){
	cin>>n>>m;
	for(int i=0;i<n;i++) cin>>dat[i];
	for(int j=0;j<=m;j++){
		dp[n-1][j]=mini(j, dat[n-1]);
	}
	for(int i=n-2;i>=0;i--){
		for(int j=0;j<=m;j++){
			ll cur=mini(j, dat[i]);
			dp[i][j]=dp[i+1][2*j/3];
			if (i+2<n) dp[i][j]=maxi(dp[i][j], dp[i+2][j]);
			if (i+3<n) dp[i][j]=maxi(dp[i][j], dp[i+3][m]);
			dp[i][j]+=cur;
		}
	}
	ll ans=0;
	for(int i=0;i<n-1;i++) ans=maxi(ans, dp[i][m]);
	cout<<ans<<endl;
}
