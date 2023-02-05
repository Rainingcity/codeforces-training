#include <iostream>
#include <string>
#include <vector>
using namespace std;
int n,m,k;
vector<string> v;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
int cnt=0,tot=0;
bool valid(int x, int y){
	return 0<=x && x<n && 0<=y && y<m;
}
void dfs(int x, int y){
	v[x][y]='&';cnt++;
	if (cnt==k) return;
	for(int i=0;i<4 && cnt<k;i++){
		int nx=x+dx[i],ny=y+dy[i];
		if (valid(nx,ny) && v[nx][ny]=='.'){
			dfs(nx, ny);
		}
	}
}
int main(){
	cin>>n>>m>>k;
	for(int i=0;i<n;i++){
		string s;cin>>s;
		v.push_back(s);
		for(int j=0;j<m;j++){
			if (v[i][j]=='.') tot++;
		}
	}
	k=tot-k;
	for(int i=0;i<n && cnt<k;i++){
		for(int j=0;j<m && cnt<k;j++){
			if (v[i][j]=='.'){
				dfs(i,j);
			}
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if (v[i][j]=='#') cout<<'#';
			else if (v[i][j]=='.') cout<<'X';
			else cout<<'.';
		}cout<<endl;
	}
	return 0;
}
