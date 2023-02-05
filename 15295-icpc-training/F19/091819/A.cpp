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
const pii zero = make_pair(0, 0);
int n;
vector<int> v;
vector<ll> dp;
set<pii> ans;
int ansx, ansy;
pii vis[300100];
void find_answer(int cur){
	if (vis[cur]!=zero){
		if (ansx!=vis[cur].first || ansy!=vis[cur].second){
			ans.insert(make_pair(-1,-1));
			ans.insert(make_pair(-1,-2));
			return;
		}
		return;
	}
	vis[cur]=make_pair(ansx, ansy);
	if (cur==0){
		ans.insert(make_pair(ansx, ansy));
		return;
	}
	if (dp[cur]==0) return;
	if (dp[cur]==1 || dp[cur]==3){
		ansy++;
		find_answer(cur-3);
		ansy--;
	}
	if (ans.size()>=2) return;
	if (dp[cur]==2 || dp[cur]==3){
		ansx++;
		find_answer(cur-2);
		ansx--;
	}
	return;
}
bool judge2(int i){
	if (i<1) return 0;
	if (v[i]-v[i-1]>=2000) return 0;
	if (i==1) return 1;
	if (v[i-1]-v[i-2]<=1000) return 0;
	return (dp[i-1]!=0);
}
bool judge3(int i){
	if (i<2) return 0;
	if (v[i]-v[i-1]>=2000 || v[i-1]-v[i-2]>=2000) return 0;
	if (i==2) return 1;
	if (v[i-2]-v[i-3]<=1000) return 0;
	return (dp[i-2]!=0);
}
int main(){
	cin>>n;
	dp.resize(n+1,0);
	for(int i=0;i<n;i++){
		int x;cin>>x;v.push_back(x);
	}
	for(int i=1;i<n;i++){
		if (judge2(i)){
			dp[i+1]+=2;
		}
		if (judge3(i)){
			dp[i+1]+=1;
		}
//		cout<<dp[i+1]<<endl;
	}
	if (dp[n]==0){
		cout<<"Impossible"<<endl;
	}else{
		find_answer(n);
		if (ans.size()==1){
			cout<<"Cars without trailers: "<<ans.begin()->first<<endl;
			cout<<"Cars with trailers: "<<ans.begin()->second<<endl;
		}else{
			cout<<"Ambiguous"<<endl;
		}
	}
	return 0;
}
