#include <iostream>
#include <vector>
#include <cstdlib>
#include <cstdio>
using namespace std;
typedef long long ll;
bool f[1001000];
vector<ll> v;
void xianxingshai(int x){
	for(int i=2;i<=x;i++){
		if (!f[i]) v.push_back((ll)i);
		for(int j=0;j<v.size();j++){
			if (i*v[j]>x) break;
			f[i*v[j]]=true;
			if (i%v[j]==0) break;
		}
	}
}
bool binsearch(ll x){
	int l=0,r=v.size();
	while(l<=r){
		int mid=(l+r)>>1;
		ll res=v[mid]*v[mid];
		if (res==x) return true;
		else if (res<x) l=mid+1;
		else r=mid-1;
	}
	return false;
}
int main(){
	xianxingshai(1000000);
	int n;cin>>n;
	for(int i=0;i<n;i++){
		ll x;cin>>x;
		if (binsearch(x)) puts("YES");
		else puts("NO");
	}
}
