#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>
using namespace std;
typedef long long ll;
ll n;
vector<ll> v;
ll ans0, ansp, ansn;
void solve(){
	ll cur0pos=-1;
	for(ll i=0;i<n;i++){
		if (v[i]==0){
			ans0+=(i-cur0pos)*(n-i);
			ll cur=1,nump=1,numn=0;
			for(ll j=cur0pos+1;j<i;j++){
				cur=cur*v[j];
				if (cur==1) nump++;
				else numn++;
			}
			ansp+=nump*(nump-1)/2+numn*(numn-1)/2;
			ansn+=nump*numn;
			cur0pos=i;
		}
	}
	ll cur=1,nump=1,numn=0;
	for(ll j=cur0pos+1;j<n;j++){
		cur=cur*v[j];
		if (cur==1) nump++;
		else numn++;
	}
	ansp+=nump*(nump-1)/2+numn*(numn-1)/2;
	ansn+=nump*numn;
	cout<<ansn<<" "<<ans0<<" "<<ansp<<endl;
	return;
}
int main(){
	cin>>n;
	for(ll i=0;i<n;i++){
		ll x;cin>>x;
		if (x>0) v.push_back(1);
		else if (x==0) v.push_back(0);
		else v.push_back(-1);
	}
	solve();
}
