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

int n;
vector<ll> v;
vector<ll> w;

bool try_move(ll b){
	if (v[n-1]<b) return false;
	if ((v[n-2]+v[n-1])/2<b) return false;
	for(int i=2;i<n;i++){
		w[i]=v[i]/3;
	}
	w[0]=w[1]=w[n]=w[n+1]=0;
	for(int i=n-1;i>=0;i--){
		ll curr=v[i]-w[i]*3+w[i+1]+w[i+2]*2;
		if (curr<b){
			if (w[i]*3<b-curr) return false;
			else{
				w[i]-=(b-curr+2)/3;
			}
		}
	}
	return true;
}

void work(){
	cin>>n;
	w.clear();
	w.resize(n+2);
	v.clear();
	ll sum=0;
	for(int i=0;i<n;i++){
		ll x;cin>>x;
		v.push_back(x);
		sum+=x;
	}
	ll l=0,r=sum/n;
	while(l<r){
		ll mid=(l+r+1)>>1;
		if (try_move(mid)) l=mid;
		else r=mid-1;
	}
	cout<<l<<endl;
	return;
}

int main(){
	int T;cin>>T;
	while(T--){
		work();
	}
}
