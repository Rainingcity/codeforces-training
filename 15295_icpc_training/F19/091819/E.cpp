#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
multiset<pii> st;
int n,m;
vector<pii> v;
bool cmp(pii a, pii b){
	if (a.second != b.second) return a.second < b.second;
	return a.first < b.first;
}
int main(){
	cin>>n>>m;
	for(int i=0;i<n;i++){
		int t,d;cin>>t>>d;
		if (d==0){
			st.insert(pii(t,d));
		}else v.push_back(pii(t,d));
	}
	sort(v.begin(),v.end(), cmp);
	n=v.size();
	int cur=0, cnt=0;
	ll ans=0;
	while(!st.empty() && cnt<m){
		auto [t, d] = *st.begin();st.erase(st.begin());
		ans+=t;
		cnt++;
		while(cur<n && v[cur].second<=cnt){
			st.insert(v[cur]);
			cur++;
		}
	}
	if (cnt==m){
		cout<<ans<<endl;
	}else cout<<"IMPOSSIBLE"<<endl;
	return 0;
}
