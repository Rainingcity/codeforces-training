#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <set>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MOD = 998244353;
int n,m;
int dat[510];
int multi(int x, int y){
	ll ans=x;
	ans*=y;ans%=(ll)MOD;
	return (int)ans;
}
int multi(int x, int y, int z){
	ll ans=x;
	ans*=y;ans%=(ll)MOD;
	ans*=z;ans%=(ll)MOD;
	return (int)ans;
}
int multi(int x, int y, int z, int w){
	ll ans=x;
	ans*=y;ans%=(ll)MOD;
	ans*=z;ans%=(ll)MOD;
	ans*=w;ans%=(ll)MOD;
	return (int)ans;
}
int calc_cur(int l, int r, set<pii>& st){
	if (st.empty()) return l;
	else return st.begin()->second;
}
int dfs(int cur, int l, int r){
	if (l>r) return 1;
	if (l==r) return 1;
	if (l+1==r) return 2;
	int ans=0;
	set<pii> s1{}, s2{};
	for(int t=l;t<cur;t++) s2.emplace(make_pair(dat[t], t));
	vector<int> ansl{}, ansr{};
	for(int i=l;i<=cur;i++){
		int cur1=calc_cur(l, i-1, s1), cur2=calc_cur(i, cur-1, s2);
		ansl.push_back(multi(dfs(cur1, l, i-1), dfs(cur2, i, cur-1)));
		if (i!=cur){
			s2.erase(make_pair(dat[i], i));
			s1.insert(make_pair(dat[i], i));
		}
	}
	set<pii> s3{}, s4{};
	for(int t=cur+1;t<=r;t++) s4.emplace(make_pair(dat[t], t));
	for(int j=cur;j<=r;j++){
		if (j!=cur){
			s3.insert(make_pair(dat[j], j));
			s4.erase(make_pair(dat[j], j));
		}
		int cur3=calc_cur(cur+1, j, s3), cur4=calc_cur(j+1, r, s4);
		ansr.push_back(multi(dfs(cur3, cur+1, j), dfs(cur4, j+1, r)));
	}
	for(auto left: ansl){
		for(auto right: ansr){
			ans=(ans+((left*right)%MOD))%MOD;
		}
	}
	return ans;
}
int main(){
	cin>>n>>m;
	int st=0;
	for(int i=0;i<n;i++){
		cin>>dat[i];
		if (dat[i]==1) st=i;
	}
	cout<<dfs(st, 0, n-1)<<endl;
	return 0;
}
