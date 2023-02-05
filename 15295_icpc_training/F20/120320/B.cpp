#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
ll absi(ll x){return x<0?-x:x;}
ll maxi(ll x, ll y){return x<y?y:x;}
int n,m;
vector<ll> v;
vector<bool> rep;

ll update_dp(ll& dp_prev2, ll& dp_prev, ll cur){
	ll new_ans = maxi(dp_prev, dp_prev2+cur);
	dp_prev2=dp_prev;
	dp_prev=new_ans;
	return dp_prev;
}

void reset_dp(ll& dp_prev2, ll& dp_prev){
	dp_prev2=0;
	dp_prev=0;
	return;
}

void reset_dp(ll& dp_prev2, ll& dp_prev, ll initial){
	dp_prev2=0;
	dp_prev=initial;
	return;
}

int main(){
	cin>>n;
	m=-1;
	ll prev=1e9+7;
	for(int i=0;i<n;i++){
		ll x;cin>>x;
		if (x==prev) rep[m]=true;
		else{
			v.push_back(x);
			rep.push_back(false);
			prev=x;
			m++;
		}
	}
	m++;
	int cur_beg=0;
	ll ans=0;
	ll dp_prev2=0,dp_prev=0;
	for(int i=1;i<m-1;i++){
		if ((v[i]-v[i-1])*(v[i]-v[i+1])>0){
			if (cur_beg==i){
				update_dp(dp_prev2, dp_prev, absi(v[i]-v[i-1]));
				cur_beg++;
				if (rep[i]){
					ans += dp_prev;
					reset_dp(dp_prev2, dp_prev);
				}
			}else{
				ans+=absi(v[cur_beg]-v[i-1]);
				cur_beg=i+1;
				if (rep[i]){
					ans += absi(v[i]-v[i-1]);
					reset_dp(dp_prev2, dp_prev);
				}else reset_dp(dp_prev2, dp_prev, absi(v[i]-v[i-1]));
			}
		}else if (cur_beg==i){
			ans += update_dp(dp_prev2, dp_prev, absi(v[i]-v[i-1]));
			reset_dp(dp_prev, dp_prev);
		}
		// cout<<ans<<" "<<dp_prev2<<" "<<dp_prev<<endl;
	}
	// cout<<endl;
	if (m<3){
		ans = absi(v[m-1]-v[0]);
	}else if ((v[m-2]-v[m-3])*(v[m-2]-v[m-1])>0){
		if (!rep[m-2]) ans+=update_dp(dp_prev2, dp_prev, absi(v[m-1]-v[m-2]));
		else ans+=absi(v[m-1]-v[m-2]);
	}else{
		ans += absi(v[m-1]-v[cur_beg]);
	}
	cout<<ans<<endl;
}
