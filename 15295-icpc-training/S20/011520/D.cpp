#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
int n;ll L,B;
vector<ll> v;
int main(){
	cin>>n>>L>>B;
	for(int i=0;i<n;i++){
		int x;cin>>x;v.push_back(x);
	}
	sort(v.begin(),v.end());
	int l=0, r=0;
	int pos=0;
	ll sum=0;
	int ans=0;
	while(r<n && sum<=B){
		ans=r;
		sum+=v[r]-v[pos];
		r++;
		if ((r>>1)!=pos) pos++;
		// cout<<0<<" "<<pos<<" "<<r<<" "<<sum<<endl;
	}
	if (r==n){
		if (sum<=B){
			cout<<n<<endl;
		}else{
			cout<<n-1<<endl;
		}
		return 0;
	}
	while(r<n){
		sum-=v[pos]-v[l];
		l++;
		if (((r+l)>>1)!=pos) pos++;
		// cout<<l<<" "<<pos<<" "<<r<<" "<<sum<<endl;
		while(r<n && sum<=B){
			ans=max(ans,(r-l));
			sum+=v[r]-v[pos];
			r++;
			if (((r+l)>>1)!=pos) pos++;
			// cout<<l<<" "<<pos<<" "<<r<<" "<<sum<<endl;
		}
	}
	if (sum<=B) ans=max(ans, (r-l));
	cout<<ans<<endl;
}
