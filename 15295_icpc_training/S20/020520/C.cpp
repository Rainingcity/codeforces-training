#include <iostream>
#include <string>
#include <vector>
using namespace std;
int n,m;
vector<int> v;
bool f[1010][1010];
string ans="";
bool F=0;
bool valid(int x){
	return 0<=x && x<=m;
}
void dfs(int cursum, int cur, string s){
	if (f[cursum][cur]) return;
	// cout<<cursum<<" "<<cur<<" "<<s<<endl;
	f[cursum][cur]=1;
	if (cur==n){
		ans=s;
		F=1;
		return;
	}
	if (valid(cursum+v[cur])) dfs(cursum+v[cur], cur+1, s+"+");
	if (F) return;
	if (valid(cursum-v[cur])) dfs(cursum-v[cur], cur+1, s+"-");
	if (F) return;
	if (ans.length()<s.length()) ans=s;
	return;
}
int main(){
	cin>>n>>m;
	for(int i=0;i<n;i++){
		int x;cin>>x;v.push_back(x);
	}
	dfs(0,0,"");
	cout<<ans.length()<<endl;
	cout<<ans<<endl;
}
