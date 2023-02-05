#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
ll maxi(ll x, ll y){return x<y?y:x;}
ll maxi(ll x, ll y, ll z){return maxi(x,maxi(y,z));}
int n;
vector<ll> dp[2];
vector<ll> v[2];
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		ll x;cin>>x;v[0].push_back(x);
	}
	for(int i=0;i<n;i++){
		ll x;cin>>x;v[1].push_back(x);
	}
	dp[0].resize(n+1,0);
	dp[1].resize(n+1,0);
	dp[0][0]=dp[1][0]=0;
	dp[0][1]=v[0][0];dp[1][1]=v[1][0];
	ll ans=maxi(v[0][0], v[1][0]);
	for(int i=1;i<n;i++){
		dp[0][i+1]=maxi(dp[0][i-1], dp[1][i-1], dp[1][i])+v[0][i];
		dp[1][i+1]=maxi(dp[0][i-1], dp[1][i-1], dp[0][i])+v[1][i];
		ans=maxi(ans,dp[0][i+1]);
		ans=maxi(ans,dp[1][i+1]);
	}
	cout<<ans<<endl;
	return 0;
}
