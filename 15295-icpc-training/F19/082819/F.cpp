#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;
ll n, A, B;
vector<ll> v;
ll pdf(ll t, ll x, ll y){
	if (t<=x+1) return (t-1)*t/2;
	else if (t<=y+1) return x*(x+1)/2+(t-x-1)*x;
	else return x*y-(x+y-t)*(x+y-t+1)/2;
}
ll search(ll st, ll tar){
	ll l=st, r=n-1;
	while(l<r){
		ll mid=(l+r+1)>>1;
		if (v[mid]<tar) l=mid;
		else r=mid-1;
	}
	return l;
}
ll gcd(ll x, ll y){
	return (y==0?x:gcd(y, x%y));
}
int main(){
	cin>>n>>A>>B;
	for(ll i=0;i<n;i++){
		ll x;cin>>x;v.push_back(x);
	}
	sort(v.begin(), v.end());
	double ans=0;
	ll x,y;
	for(ll i=0;i<n-1;i++){
		ll j=search(i+1, B-v[i]);
		if (j<=i) break;
		ll curx=pdf(B, v[i], v[j])-pdf(A-1, v[i], v[j]), cury=v[i]*v[j];
		double curans=(double)curx/cury;
		if (ans<curans){
			ans=curans;
			x=curx;
			y=cury;
		}
	}
	ll g=gcd(x,y);
	x/=g;y/=g;
	cout<<x<<"/"<<y<<endl;
	return 0;
}
