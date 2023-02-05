#include<cstdio>
#include<vector>
#include<cstring>
using namespace std;
typedef pair<int,int> pii;
int n;
vector<pii> v[100100];
vector<pii> vt[100100];
int ans[100100];
vector<int> ansv;
bool vis[100100];
void buildtree(int cur){
	vis[cur]=true;
	for(int i=0;i<v[cur].size();i++){
		if (vis[v[cur][i].first]) continue;
		vt[cur].push_back(v[cur][i]);
		buildtree(v[cur][i].first);
	}
}
void dfs(int cur){
	ans[cur]=0;
	for(int i=0;i<vt[cur].size();i++){
		int nx=vt[cur][i].first;
		dfs(nx);
		if (ans[nx]!=0) ans[cur]+=ans[nx];
		else if (vt[cur][i].second){
			ans[cur]+=1;
			ansv.push_back(nx);
		}
	}
}
int main(){
	scanf("%d", &n);
	for(int i=1;i<n;i++){
		int x,y,z;scanf("%d%d%d", &x, &y, &z);x--;y--;z--;
		v[x].push_back(make_pair(y,z));v[y].push_back(make_pair(x,z));
	}
	memset(vis,false,sizeof(vis));
	buildtree(0);dfs(0);
	printf("%d\n", ans[0]);
	if (ans[0]>0){
		printf("%d", ansv[0]+1);
		for(int i=1;i<ans[0];i++) printf(" %d", ansv[i]+1);
		puts("");
	}
	return 0;
}
