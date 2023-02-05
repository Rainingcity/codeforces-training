#include <iostream>
#include <vector>
#include <string>
using namespace std;
const int inf = 100000;
vector<vector<vector<int>>> dp{};
vector<int> path{};
int n,m;
int main(){
	cin>>n>>m;
	dp.resize(3*n+1);
	for(int i=0;i<=3*n;i++){
		dp[i].resize(m+1);
		for(int j=0;j<=m;j++){
			dp[i][j].resize(m+1, inf);
		}
	}
	path.push_back(0);
	for(int i=0;i<n;i++){
		int x,y;cin>>x>>y;
		path.push_back(x);
		path.push_back(y);
		path.push_back(0);
	}
	string weather = "X";
	for(int i=0;i<n;i++){
		string s;cin>>s;
		weather += s;
	}
	dp[0][0][0]=0;
	for(int i=1;i<=3*n;i++){
		int cur=path[i], prev=path[i-1];
		if (weather[i]=='S'){
			for(int j=0;j<=m;j++){
				for(int k=0;k<=m;k++){
					dp[i][j][k]=dp[i-1][j][k];
					if (j==cur){
						dp[i][j][k]=min(dp[i][j][k], dp[i-1][prev][k]+1);
					}else if (k==cur){
						dp[i][j][k]=min(dp[i][j][k], dp[i-1][j][prev]+1);
					}
					if (j==cur && k==path[i]){
						dp[i][j][k]=min(dp[i][j][k], dp[i-1][prev][prev]+1);
					}
				}
			}
		}else{
			for(int j=0;j<=m;j++){
				dp[i][j][cur]=dp[i-1][j][prev]+1;
				if (j==cur){
					dp[i][j][cur]=min(dp[i][j][cur], dp[i-1][prev][prev]+1);
				}
				dp[i][cur][j]=dp[i][j][cur];
			}
		}
	}
	vector<vector<int>>& lst=dp[3*n];
	int mi=inf;
	for(int j=0;j<=m;j++){
		for(int k=0;k<=m;k++){
			mi=min(mi, lst[j][k]);
		}
	}
	cout<<mi<<endl;
	return 0;
}
