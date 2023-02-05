#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <utility>
#include <cmath>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

int maxi(int x, int y){return x<y?y:x;}
int mini(int x, int y){return x<y?x:y;}

ll sum(ll x){
	return x*(x+1)/2;
}

ll reverse_sum(ll x, ll n){
	return (n+n-x+1)*x/2;
}

void work(){
	ll x,y;cin>>x>>y;
	if (sum(x)>=y){
		ll l=1,r=x;
		while(l<r){
			ll mid=(l+r)>>1;
			if (sum(mid)>=y) r=mid;
			else l=mid+1;
		}
		cout<<r<<endl;
		return;
	}else{
		ll l=1,r=x-1;
		y-=sum(x);
		while(l<r){
			// cout<<l<<" "<<r<<endl;
			ll mid=(l+r)>>1;
			if (reverse_sum(mid, x-1)>=y) r=mid;
			else l=mid+1;
		}
		cout<<r+x<<endl;
		return;
	}
	return;
}

int main(){
	int T;cin>>T;
	while(T--){
		work();
	}
}
