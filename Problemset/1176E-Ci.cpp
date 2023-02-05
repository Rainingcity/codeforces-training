/*
 * Codeforces 1176E
 * Cover it!
 */

#include <cstdio>
#include <vector>
using namespace std;
int n, m;
vector<int> vodd,veven;
vector<int> v[200200];
bool vis[200200];
void init(){
	scanf("%d%d", &n, &m);
	for(int i=0;i<n;i++){
		vis[i]=false;
		v[i].clear();
	}
	vodd.clear();veven.clear();
	for(int i=0;i<m;i++){
		int x,y;scanf("%d%d", &x, &y);
		x--;y--;
		v[x].push_back(y);
		v[y].push_back(x);
	}
}
void dfs(int cur, int dep){
	vis[cur]=true;
	if (dep&1) vodd.push_back(cur);
	else veven.push_back(cur);
	for(int i=0;i<v[cur].size();i++){
		int nxt = v[cur][i];
		if (vis[nxt]) continue;
		dfs(nxt, dep+1);
	}
}
void solve(){
	init();
	dfs(0, 0);
	if (vodd.size()>veven.size()){
		int ans = veven.size();
		printf("%d\n%d", ans, veven[0]+1);
		for(int i=1;i<ans;i++) printf(" %d", veven[i]+1);
		puts("");
	}else{
		int ans = vodd.size();
		printf("%d\n%d", ans, vodd[0]+1);
		for(int i=1;i<ans;i++) printf(" %d", vodd[i]+1);
		puts("");
	}
}
int main(){
	int T;scanf("%d", &T);
	while(T--){
		solve();
	}
	return 0;
}
