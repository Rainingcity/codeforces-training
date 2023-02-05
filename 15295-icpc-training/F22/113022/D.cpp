#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;
int maxi(int x, int y){return x<y?y:x;}

int n;
vector<int> v;
vector<int> mp;
vector<int> dp;

int main(){
	scanf("%d", &n);
	mp.resize(1000000,-1);
	dp.resize(n,1);

	for(int i=0;i<n;i++){
		int x;scanf("%d", &x);
		v.push_back(x);
		mp[x]=i;
	}
	int mx=v[n-1];
	int ans=0;
	for(int i=0;i<n;i++){
		ans=maxi(ans, dp[i]);
		for(int j=2;j*v[i]<=mx;j++){
			if (mp[j*v[i]]!=-1){
				dp[mp[j*v[i]]]=maxi(dp[mp[j*v[i]]], dp[i]+1);
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
