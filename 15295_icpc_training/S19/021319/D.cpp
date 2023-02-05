#include<cstdio>
#include<vector>
#include<cstring>
using namespace std;
int n,m;
pair<int,int> a[110];
int ans[110];
vector<int> v[110];
bool vis[110];
void dfs(int cur, int val){
	vis[cur]=true;
	ans[cur]=val;
	int nxval=(val==1?2:1);
	for(int i=0;i<v[cur].size();i++){
		int nx=v[cur][i];
		if (!vis[nx]){
			dfs(nx,nxval);
		}else{
			if (nxval!=ans[nx]) ans[nx]=3;
		}
	}
}
int main(){
	scanf("%d%d", &n, &m);
	for(int i=0;i<m;i++){
		int x,y;scanf("%d%d", &x, &y);
		x--;y--;
		a[i]=make_pair(x,y);
		for(int j=0;j<i;j++){
			if (a[j].first==x || a[j].second==x || a[j].first==y || a[j].second==y) continue;
			if ((a[j].first-x)*(x-a[j].second)*(a[j].first-y)*(y-a[j].second)<0){
				v[i].push_back(j);v[j].push_back(i);
			}
		}
	}
	for(int i=0;i<m;i++){
		if (!vis[i]){
			dfs(i,1);
		}
	}
	for(int i=0;i<m;i++) if (ans[i]==3){
		puts("Impossible");
		return 0;
	}
	for(int i=0;i<m;i++){
		if (ans[i]==1) printf("i");
		else printf("o");
	}
	puts("");
	return 0;
}
