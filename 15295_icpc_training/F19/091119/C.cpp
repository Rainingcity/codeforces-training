#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
typedef long long ll;
const ll inf = 0x5f5f5f5f5f5f5f5fl;
int n,m,k;
ll dp[110][110][110];
ll cost[110][110];
ll cumcost[110][110];
ll mn1[110][110], mn1c[110][110];
ll mn2[110][110];
ll init[110];
void update_min(int i, int c, int j, ll x){
	if (x==-1) return;
	if (mn1[i][j]==-1){
		mn1[i][j]=x;
		mn1c[i][j]=c;
		return;
	}
	if (mn2[i][j]==-1){
		if (x<mn1[i][j]){
			mn2[i][j]=mn1[i][j];
			mn1[i][j]=x;
			mn1c[i][j]=c;
		}else mn2[i][j]=x;
		return;
	}
	if (x>=mn2[i][j]) return;
	if (x>=mn1[i][j]){
		mn2[i][j]=x;
		return;
	}
	mn2[i][j]=mn1[i][j];
	mn1[i][j]=x;mn1c[i][j]=c;
}
void calc_dp(int i, int c, int l, int j, ll cst){
	if (c==mn1c[j][l-1]){
		if (mn2[j][l-1]==-1) return;
		if (dp[i][c][l]==-1) dp[i][c][l]=mn2[j][l-1]+cst;
		else dp[i][c][l]=min(dp[i][c][l], mn2[j][l-1]+cst);
	}else{
		if (mn1[j][l-1]==-1) return;
		if (dp[i][c][l]==-1) dp[i][c][l]=mn1[j][l-1]+cst;
		else dp[i][c][l]=min(dp[i][c][l], mn1[j][l-1]+cst);
	}
	return;
}
int main(){
	cin>>n>>m>>k;
	for(int i=0;i<n;i++) cin>>init[i];
	for(int i=0;i<n;i++){
		for(int c=0;c<m;c++){
			cin>>cost[i][c];
			cumcost[i+1][c]=cumcost[i][c]+cost[i][c];
		}
	}
	memset(dp, -1, sizeof(dp));
	memset(mn1, -1, sizeof(mn1));
	memset(mn2, -1, sizeof(mn2));
	memset(mn1c, -1, sizeof(mn1c));
	for(int c=0;c<m;c++){
		dp[0][c][0]=0;
		mn1[0][0]=0;
		mn2[0][0]=0;
	}
	for(int i=1;i<=n;i++){
//		cout<<"i="<<i<<":\n";
		for(int l=1;l<=k && l<=i;l++){
//			cout<<"	l="<<l<<":\n";
			for(int c=0;c<m;c++){
//				cout<<"		c="<<c<<":\n";
				ll delsum=0;
				for(int j=i-1;j>=l-1;j--){
					if (init[j]!=0 && init[j]!=c+1) break;
					if (init[j]!=0) delsum+=cost[j][c];
					calc_dp(i, c, l, j, cumcost[i][c]-cumcost[j][c]-delsum);
				}
//				cout<<"			dp[i][c][l]="<<dp[i][c][l]<<endl;
				update_min(i, c, l, dp[i][c][l]);
			}
		}
	}
	cout<<mn1[n][k]<<endl;
	return 0;
}
