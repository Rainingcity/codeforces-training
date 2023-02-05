#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

ll n,m,k;
vector<ll> v,w,wp;

ll count(ll tar){
	ll cnt=0;
	for(int i=0,j=k-1;i<m && v[i]<tar;i++){
		while(j>=0 && v[i]+w[j]>tar) j--;
		cnt+=j+1;
	}
	return cnt;
}

int main(){
	cin>>m>>k>>n;
	for(int i=0;i<m;i++){
		ll x;cin>>x;
		v.push_back(x);
	}

	sort(v.begin(), v.end());

	for(int i=0;i<k;i++){
		ll x;cin>>x;
		w.push_back(x);
	}

	sort(w.begin(), w.end());

	ll sum=0;
	wp.push_back(0);
	for(int i=0;i<k;i++){
		sum+=w[i];
		wp.push_back(sum);
	}

	if (n==0){
		cout<<0<<endl;
		return 0;
	}

	ll l=2, r=5000000;
	while(l<r){
		int mid=(l+r)>>1;
		if (count(mid)<n) l=mid+1;
		else r=mid;
	}

	ll ex = count(r)-n;

	sum = 0;
	for(int i=0,j=k-1;i<m && v[i]<r;i++){
		while(j>=0 && v[i]+w[j]>r) j--;
		sum += wp[j+1] + (j+1)*v[i];
	}

	sum -= ex * r;
	cout<<sum<<endl;
	return 0;
}
