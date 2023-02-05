#include <iostream>
#include <utility>
#include <vector>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
ll absi(ll x){return x<0?-x:x;}

ll x1,y1,x2,y2;
ll sumx, sumy;
int n;
vector<pll> v;

bool check(ll x){
	ll rd=x/n, id=x%n;
	ll nx=x2-rd*sumx-v[id].first, ny=y2-rd*sumy-v[id].second;
	return absi(nx-x1)+absi(ny-y1)<=x;
}

int main(){
	cin>>x1>>y1>>x2>>y2>>n;
	string s;cin>>s;
	for(int i=0;i<n;i++){
		v.push_back(make_pair(sumx,sumy));
		if (s[i]=='U'){
			sumy++;
		}else if (s[i]=='D'){
			sumy--;
		}else if (s[i]=='L'){
			sumx--;
		}else if (s[i]=='R'){
			sumx++;
		}else{
			exit(1);
		}
	}
	ll l=0, r=n*(absi(x1-x2)+absi(y1-y2));
	ll MX=r;
	while(l<r){
		ll mid=(l+r)>>1;
		if (check(mid)) r=mid;
		else l=mid+1;
	}
	if (!check(l)) puts("-1");
	else printf("%lld\n", l);
	return 0;
}
