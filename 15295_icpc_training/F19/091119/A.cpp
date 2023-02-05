#include <iostream>
#include <string>
using namespace std;
string s;
int n;
int ans[1010][1010];
int check(int x, int y){
	if (x==0) return y;
	if (y==0) return x;
	if (x==1 || y==1) return 1;
	else return -1;
}
int dfs(int l, int r){
	if (ans[l][r]!=0) return ans[l][r];
	if (r-l==0) return (ans[l][r]=1);
	if (r-l==1){
		if (s[l]==s[r]) return (ans[l][r]=1);
		else return (ans[l][r]=-1);
	}
	if (s[l]==s[r]) ans[l][r]=check(ans[l][r], dfs(l+1,r-1));
	if (s[l]==s[l+1]) ans[l][r]=check(ans[l][r], dfs(l+2,r));
	if (s[r]==s[r-1]) ans[l][r]=check(ans[l][r], dfs(l,r-2));
	if (ans[l][r]==0) ans[l][r]=-1;
	return ans[l][r];
}
int main(){
	cin>>s;
	n=s.length();
	dfs(0,n-1);
	if (ans[0][n-1]==1) cout<<"POSSIBLE"<<endl;
	else cout<<"IMPOSSIBLE"<<endl;
	return 0;
}
