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

ll reverse_sum_with_tail(ll x, ll n){
	if (x<=n) return (n+n-x+1)*x/2;
	else return n*(n+1)/2+(x-n);
}

ll calc_min_pillow(ll p, ll n, ll k){
	if (p==1) return n;
	else return p+reverse_sum_with_tail(k-1, p-1)+reverse_sum_with_tail(n-k, p-1);
}

int main(){
	ll n,m,k;
	cin>>n>>m>>k;
	ll l=1,r=m-n+1;
	while(l<r){
		ll mid=(l+r+1)>>1;
		if (calc_min_pillow(mid, n, k)>m) r=mid-1;
		else l=mid;
	}
	cout<<l<<endl;
	return 0;
}
