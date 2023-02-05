#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
typedef long long ll;
ll n,k;
vector<ll> v;
bool check(ll m){
	ll cur=0, row=0, i=0, cur_rem=v[0];
	while(i<n && row<k){
		// printf("%d %d %d %d\n", cur, row, i, cur_rem);
		if (cur==0){
			row+=cur_rem/m;
			cur=cur_rem%m;
			i++;
			if (i<n) cur_rem=v[i];
		}else if (cur_rem+cur>m){
			cur_rem-=(m-cur);
			cur=0;
			row++;
		}else if (cur_rem+cur==m){
			cur=0;
			i++;
			if (i<n) cur_rem=v[i];
			row++;
		}else{
			cur=cur_rem;
			i++;
			if (i<n) cur_rem=v[i];
		}
	}
	// printf("%d %d\n", m, row);
	return row>=k;
}
void solve(){
	v.clear();
	scanf("%lld%lld", &n, &k);
	ll l=0,r=0,sum=0;
	for(int i=0;i<n;i++){
		ll x;scanf("%lld", &x);
		v.push_back(x);
		sum+=x;
	}
	r=sum/k;
	while(l<r){
		ll mid=(l+r+1)>>1;
		if (check(mid)) l=mid;
		else r=mid-1;
	}
	printf("%lld\n", l*k);
	return;
}
int main(){
	int T;scanf("%d", &T);
	while(T--){
		solve();
	}
}
