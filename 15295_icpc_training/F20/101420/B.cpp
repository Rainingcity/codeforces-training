#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
int n;
ll m;
vector<ll> v;
vector<ll> psum;
bool check(ll med){
	int l=0,r=n-1;
	while(l<r){
		int mid=(l+r+1)>>1;
		if (v[mid]<med) l=mid;
		else r=mid-1;
	}
	ll res=med*(l-n/2+1)-(psum[l]-psum[n/2-1]);
	if (res>m) return false;
	else return true;
}
int main(){
	cin>>n>>m;
	for(int i=0;i<n;i++){
		int x;cin>>x;
		v.push_back(x);
	}
	if (n==1){
		cout<<v[0]+m<<endl;
		return 0;
	}

	sort(v.begin(),v.end());
	ll cur_sum = 0;
	for(int i=0;i<n;i++){
		cur_sum+=v[i];
		psum.push_back(cur_sum);
	}

	ll l=v[n/2], r=1;
	while(check(l+r)){
		r<<=1;
	}
	r>>=1;
	l+=r;
	r+=l;

	while(l<r){
		ll mid=(l+r+1)>>1;
		if (check(mid)) l=mid;
		else r=mid-1;
	}
	cout<<l<<endl;
	return 0;
}
