/*
 * Codeforces 1194B
 * Yet Another Crosses Problem
 */

#include <cstdio>
#include <vector>
#include <iostream>
#include <string>
using namespace std;
int mini(int x, int y){return x<y?x:y;}
void solve(){
	int n,m;cin>>n>>m;
	vector<int> row, col;
	row.resize(n);col.resize(m);
	vector<vector<bool>> v;v.resize(n);
	for(int i=0;i<n;i++){
		v[i].resize(m);
		string line;cin>>line;
		for(int j=0;j<m;j++){
			if (line[j]=='*'){
				v[i][j]=true;
			}else{
				v[i][j]=false;
				row[i]++;col[j]++;
			}
		}
	}
	int ans = n+m;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if (v[i][j]){
				ans = mini(ans, row[i]+col[j]);
			}else{
				ans = mini(ans, row[i]+col[j]-1);
			}
		}
	}
	cout<<ans<<endl;
	return;
}
int main(){
	int T;cin>>T;
	while(T--){solve();}
	return 0;
}
