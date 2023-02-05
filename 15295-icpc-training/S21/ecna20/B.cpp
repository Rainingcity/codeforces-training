#include <iostream>
#include <vector>
#include <string>
using namespace std;
int n,m,k,slen;
string s;
vector<vector<char>> mp;
bool dp[11][11][110][110][8];
int dx[8]={-1,-1,-1,0,0,1,1,1};
int dy[8]={-1,0,1,-1,1,-1,0,1};

int main(){
	cin>>n>>m;
	mp.resize(n);
	for(int i=0;i<n;i++){
		mp[i].resize(m);
		for(int j=0;j<m;j++){
			cin>>mp[i][j];
		}
	}
	cin>>k;
	cin>>s;slen=s.length();
	if (k<0 || k>=slen){
		cout<<"No"<<endl;
		return 0;
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if (mp[i][j]==s[0]){
				for(int d=0;d<8;d++) dp[i][j][0][0][d]=true;
			}
		}
	}
	for(int it=1;it<slen;it++){
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if (mp[i][j]!=s[it-1]) continue;
				for(int l=0;l<=k;l++){
					int cnt=0;
					for(int d=0;d<8;d++) cnt+=dp[i][j][it-1][l][d];
					if (cnt==0) continue;
					for(int d=0;d<8;d++){
						int ni=i+dx[d], nj=j+dy[d];
						if (ni<0 || ni>=n || nj<0 || nj>=m) continue;
						if (mp[ni][nj]!=s[it]) continue;
						dp[ni][nj][it][l+(!dp[i][j][it-1][l][d])][d]=true;
						if (cnt>1 && it>1) dp[ni][nj][it][l+1][d]=true;
					}
				}
			}
		}
	}
	bool F=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if (mp[i][j]==s[slen-1]){
				for(int d=0;d<8;d++){
					F|=dp[i][j][slen-1][k][d];
				}
			}
		}
	}
	if (F) cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
	return 0;
}
