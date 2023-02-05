#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef long long ll;
int n;
vector<int> v;
int c[200010];
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		int x;cin>>x;v.push_back(x);
		c[x]++;
	}
	for(int i=1;i<=200000;i++){
		c[i]+=c[i-1];
	}
	sort(v.begin(),v.end());
	ll ans=0;
	for(int i=0;i<n;i++){
		if (i && v[i]==v[i-1]) continue;
		ll cur=0;
		for(ll j=v[i]-1;j<=200000;j+=v[i]){
			cur+=(ll)(c[(j+v[i]>200000?200000:j+v[i])]-c[j])*(j+1);
		}
		if (cur>ans) ans=cur;
	}
	cout<<ans<<endl;
	return 0;
}
