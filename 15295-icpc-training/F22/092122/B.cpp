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
int absi(int x){return x<0?-x:x;}

int n,k,p;
int dp[1010][2020];
vector<int> v,w;

int calc(int x, int y){
	return absi(x-y)+absi(y-p);
}

int main(){
	cin>>n>>k>>p;
	memset(dp, 0, sizeof(dp));
	for(int i=0;i<n;i++){
		int x;cin>>x;v.push_back(x);
	}
	sort(v.begin(),v.end());
	for(int i=0;i<k;i++){
		int x;cin>>x;w.push_back(x);
	}
	sort(w.begin(),w.end());
	dp[0][0]=calc(v[0], w[0]);
	for(int j=1;j<k;j++) dp[0][j]=mini(dp[0][j-1], calc(v[0], w[j]));
	for(int i=1;i<n;i++){
		dp[i][i]=maxi(dp[i-1][i-1],calc(v[i],w[i]));
		for(int j=i+1;j<k;j++){
			dp[i][j]=mini(maxi(dp[i-1][j-1],calc(v[i], w[j])),dp[i][j-1]);
		}
	}
	cout<<dp[n-1][k-1]<<endl;
	return 0;
}
