#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef long long ll;
string s;
vector<bool> v;
ll find1(ll pos){
	for(ll i=pos+1;i<v.size();i++){
		if (v[i]) return i;
	}
	return v.size();
}
ll form_int(ll st, ll ed){
	ll sum=0;
	for(ll i=st;i<ed;i++){
		sum<<=1;
		sum+=v[i];
	}
	return sum;
}
ll solve(){
	cin>>s;
	ll n=s.length();
	v.clear();
	for(ll i=0;i<n;i++){
		v.push_back(s[i]-'0');
	}
	ll it=-1;
	ll ans=0;
	while(it<n){
		ll new_it=find1(it);
		if (new_it==n) break;
		ll cnt=new_it-it-1;
		ll cur=0;
		for(int i=new_it;i<n && cur<=i-it;i++){
			cur<<=1;
			cur+=v[i];
			if (cur<=i-it) ans++;
		}
		it=new_it;
	}
	return ans;
}
int main(){
	int T;cin>>T;
	while(T--){
		cout<<solve()<<endl;
	}
}
