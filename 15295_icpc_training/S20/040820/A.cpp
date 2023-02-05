#include <iostream>
using namespace std;
typedef long long ll;
ll absi(ll x){return x<0?-x:x;}
ll crossproduct(ll x1, ll y1, ll x2, ll y2){
	return (x1*y2-x2*y1);
}
ll calc(){
	int n;cin>>n;
	ll ret=0;
	ll cx, cy;cin>>cx>>cy;
	ll sx=cx, sy=cy;
	for(int i=1;i<n;i++){
		ll nx,ny;cin>>nx>>ny;
		ret+=crossproduct(cx, cy, nx, ny);
		// cout<<cx<<" "<<cy<<" "<<nx<<" "<<ny<<" "<<ret<<endl;
		cx=nx;cy=ny;
	}
	ret+=crossproduct(cx, cy, sx, sy);
	return absi(ret);
}
int main(){
	int T;cin>>T;
	double sum=0;
	while(T--){
		sum+=calc()/2.0;
	}
	cout<<(ll)sum<<endl;
	return 0;
}
