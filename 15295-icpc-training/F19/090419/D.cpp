#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
ll n, m;
vector<ll> cost;
vector<ll> earn;
ll calc(ll days){
	ll sum=0;
	for(ll i=0;i<n;i++){
		if (earn[i]*days>cost[i]) sum+=earn[i]*days-cost[i];
	}
	return sum;
}
int main(){
	cin>>n>>m;
	for(ll i=0; i<n; i++){
		ll x;cin>>x;earn.push_back(x);
		cin>>x;cost.push_back(x);
	}
	ll l=0, r=(m+cost[0])/earn[0]+1;
	while(l<r){
		ll mid=(l+r)/2;
		if (calc(mid)>=m) r=mid;
		else l=mid+1;
	}
	cout<<r<<endl;
	return 0;
}
