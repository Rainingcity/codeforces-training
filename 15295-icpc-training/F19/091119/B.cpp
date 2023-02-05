#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;
typedef long long ll;
int n;
vector<ll> cost;
vector<string> v;
vector<string> vr;
vector<ll> dp[2];
void update(ll& tar, ll prev, ll c){
	if (prev==-1) return;
	if (tar==-1){
		tar=prev+c;
		return;
	}
	tar=min(tar, prev+c);
	return;
}
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		ll x;cin>>x;cost.push_back(x);
	}
	for(int i=0;i<n;i++){
		string s;cin>>s;v.push_back(s);
		string t="";
		for(auto c: s){
			t=c+t;
		}
		vr.push_back(t);
	}
	dp[0].resize(n, -1);
	dp[1].resize(n, -1);
	dp[0][0]=0;
	dp[1][0]=cost[0];
	for(int i=1;i<n;i++){
		if (v[i]>=v[i-1]){
			update(dp[0][i], dp[0][i-1], 0);
		}
		if (v[i]>=vr[i-1]){
			update(dp[0][i], dp[1][i-1], 0);
		}
		if (vr[i]>=v[i-1]){
			update(dp[1][i], dp[0][i-1], cost[i]);
		}
		if (vr[i]>=vr[i-1]){
			update(dp[1][i], dp[1][i-1], cost[i]);
		}
	}
	if (dp[0][n-1]==-1 && dp[1][n-1]==-1){
		cout<<-1<<endl;
	}else if (dp[0][n-1]==-1){
		cout<<dp[1][n-1]<<endl;
	}else if (dp[1][n-1]==-1){
		cout<<dp[0][n-1]<<endl;
	}else{
		cout<<min(dp[0][n-1],dp[1][n-1])<<endl;
	}
	return 0;
}
