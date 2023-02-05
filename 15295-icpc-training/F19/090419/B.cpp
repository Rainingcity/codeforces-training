#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstdlib>
using namespace std;
typedef long long ll;
ll n,S;
vector<ll> v;
priority_queue<ll> pq;
ll calc(ll k){
	while(!pq.empty()) pq.pop();
	size_t sz=0;
	ll sum=0;
	for(ll i=0;i<n;i++){
		ll cur=v[i]+(i+1)*k;
		pq.push(cur);sum+=cur;sz++;
//		cout<<sz<<" "<<sum<<endl;
		if (sz>k){
			ll minus=pq.top();pq.pop();
//			cout<<minus<<endl;
			sum-=minus;sz--;
		}
//		cout<<sz<<" "<<sum<<endl;
	}
	return sum;
}
int main(){
	cin>>n>>S;
	for(ll i=0;i<n;i++){
		ll x;cin>>x;v.push_back(x);
	}
	ll l=0, r=n;
	while(l<r){
		ll mid=(l+r+1)>>1;
		ll res=calc(mid);
		if (res==S){
			cout<<mid<<" "<<res<<endl;
			return 0;
		}
		if (res<S){
			l=mid;
		}else{
			r=mid-1;
		}
	}
	cout<<l<<" "<<calc(l)<<endl;
	return 0;
}
