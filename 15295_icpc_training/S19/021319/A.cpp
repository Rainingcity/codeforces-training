#include<cstdio>
#include<vector>
using namespace std;
int n;
int a[2010];
vector<int> v[2010];
vector<int> hd;
bool vis[2010];
void dfs(int cur, int dep){
	a[cur]=dep;
	vis[cur]=true;
	for(int i=0;i<v[cur].size();i++){
		if (!vis[v[cur][i]]) dfs(v[cur][i],dep+1);
	}
}
int main(){
	scanf("%d", &n);
	for(int i=0;i<n;i++){
		int x;scanf("%d", &x);
		if (x==-1){
			hd.push_back(i);
			continue;
		}
		x--;
		v[x].push_back(i);
	}
	for(int i=0;i<hd.size();i++){
		if (!vis[hd[i]]){
			dfs(hd[i],1);
		}
	}
	int mx=0;
	for(int i=0;i<n;i++) if (a[i]>mx) mx=a[i];
	printf("%d\n", mx);
	return 0;
}