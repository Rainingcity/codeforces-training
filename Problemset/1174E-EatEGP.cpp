/*
 * Codeforces 1174E
 * Ehab and the Expected GCD Problem
 */

#include <cstdio>
using namespace std;
typedef unsigned int ui;
typedef long long ll;
const ll MOD = 1000000007;
int n;
ui dp[1000100][20][2];

int f(int x, int y){
	int t = n;
	for(int i=0;i<x;i++) t/=2;
	for(int i=0;i<y;i++) t/=3;
	return t;
}

int main(){
	scanf("%d", &n);
	int x=0,xs=1;
	while(xs<=n){
		x++;
		xs<<=1;
	}
	xs>>=1;x--;
	dp[1][x][0]=1;
	if (xs/2*3<=n) dp[1][x-1][1]=1;
	for(int i=1;i<n;i++){
		for(int k=0;k<=1;k++){
			int cnt1 = n;
			int cnt2 = (k==0?n:n/3), cnt2p = cnt2;
			for(int j=0;j<=x;j++){
				if (cnt2>i) dp[i+1][j][k] = ((ll)dp[i+1][j][k] + (ll)(dp[i][j][k])*(ll)(cnt2-i)) % MOD;
				if (j>=1) dp[i+1][j-1][k] = ((ll)dp[i+1][j-1][k] + (ll)(dp[i][j][k])*(ll)(cnt2p-cnt2)) % MOD;
				if (k>=1) dp[i+1][j][k-1] = ((ll)dp[i+1][j][k-1] + (ll)(dp[i][j][k])*(ll)(cnt1-cnt2)) % MOD;
				cnt2p = cnt2;
				cnt1 = cnt1 / 2;
				cnt2 = cnt2 / 2;
			}
		}
	}
	printf("%d\n", (int)dp[n][0][0]);
	return 0;
}
