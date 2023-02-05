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
vector<ll> psum;

struct ld{
	ll x,y;
	ld(){}
	ld(ll _x,ll _y){x=_x;y=_y;}
	bool operator<(ld b){
		return x*b.y<y*b.x;
	}
	ld operator-(ll b){
		return ld(x-y*b,y);
	}
};

ld ans_val;
int ansn;
vector<pii> ans;

ld mean_up(int i, int j){
	return ld(psum[i+1]-psum[i-j]+psum[n]-psum[n-j],2*j+1);
}

ld mean_down(int i, int j){
	return ld(psum[j]+psum[i+j]-psum[i-1],2*j+1);
}

int main(){
	v.clear();
	psum.clear();
	ans.clear();
	ansn=0;
	ans_val=ld(0,1);

	cin>>n;
	for(int i=0;i<n;i++){
		ll x;cin>>x;
		v.push_back(x);
	}
	sort(v.begin(),v.end());

	ll sum=0;
	psum.push_back(0);
	for(int i=0;i<n;i++){
		sum+=v[i];
		psum.push_back(sum);
	}

	ansn=1;
	ans.push_back(make_pair(0,0));
	ans.push_back(make_pair(0,-1));

	for(int i=1;i<n-1;i++){
		if (v[i]*2>v[i-1]+v[n-1]) continue;
		int l=1,r=mini(i,n-i-1);
		while(l<r){
			int mid=(l+r)>>1;
			if (mean_up(i, mid)<mean_up(i, mid-1)){
				r=mid;
			}else{
				l=mid+1;
			}
		}
		ld diff=mean_up(i, r)-v[i];
		if (ans_val<diff){
			ans_val=diff;
			ansn=2*r+1;
			ans[0]=make_pair(i-r,i);
			ans[1]=make_pair(n-r,n-1);
		}
	}

/*	for(int i=1;i<n-1;i++){
		if (v[i]*2<v[0]+v[i+1]) continue;
		int l=1,r=mini(i,n-i-1);
		while(l<r){
			int mid=(l+r)>>1;
			if (mean_down(i, mid)>mean_down(i, mid-1)){
				r=mid;
			}else{
				l=mid+1;
			}
		}
		ld diff=v[i]-mean_down(i, r);
		if (diff>ans_val){
			ans_val=diff;
			ansn=2*r+1;
			ans[0]=make_pair(0,r-1);
			ans[1]=make_pair(i,i+r);
		}
	}*/

	cout<<ansn<<endl;
	bool start=false;
	for(int i=0;i<ans.size();i++){
		for(int j=ans[i].first;j<=ans[i].second;j++){
			if (start) cout<<" ";
			else start=true;
			cout<<v[j];
		}
	}
	cout<<endl;
	return 0;
}
