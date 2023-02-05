#include <cstdio>
#include <cstring>
#include <vector>
#include <utility>
using namespace std;
int n,m,k;
vector<vector<int>> v;
int ans[500100],ansn;
vector<bool> vis;
void dfs(int cur){
	vis[cur]=true;
	ans[ansn++]=cur;
	for(auto nxt: v[cur]){
		if (vis[nxt]) continue;
		dfs(nxt);
		ans[ansn++]=cur;
	}
}
int main(){
	scanf("%d%d%d", &n, &m, &k);
	v.resize(n);
	vis.resize(n);
	for(int i=0;i<m;i++){
		int x,y;scanf("%d%d", &x, &y);x--;y--;
		v[x].push_back(y);v[y].push_back(x);
	}
	dfs(0);
	int st=0;
	int l=ansn/k;
	int rem=ansn%k;
	for(int i=0;i<k;i++){
		int ed=st;
		if (i<rem){
			printf("%d", l+1);
			ed+=l+1;
		}else{
			printf("%d", l);
			ed+=l;
		}
		for(;st<ed;st++){
			printf(" %d", ans[st]+1);
		}
		puts("");
	}
	return 0;
}
