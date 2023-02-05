#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
int n,m;
vector<int> v[100100];
vector<int> vt[100100];
bool vis[100100];
int par[100100];
int lca[100100][20];
int sm[100100];
int dist[100100];
void buildtree(int cur, int dep){
	vis[cur]=true;dist[cur]=dep;
	for(int i=0;i<v[cur].size();i++){
		int nx=v[cur][i];
		if (vis[nx]) continue;
		vt[cur].push_back(nx);par[nx]=cur;
		buildtree(nx, dep+1);
	}
}
int lx[100100],ly[100100];
int findlca(int x, int y){
	if (dist[x]<dist[y]){
		x=x^y;y=x^y;x=x^y;
	}
	int s=1,t=0;
	while(dist[x]>=dist[y]+s){
		t++;s<<=1;
	}t--;s>>=1;
	while(t>=0){
		x=lca[x][t];
		while(t>=0 && dist[x]<dist[y]+s){
			t--;s>>=1;
		}
	}
	if (x==y) return y;
	if (par[x]==par[y]) return par[x];
	t=1;
	while(lca[x][t]!=lca[y][t]) t++;
	t--;
	while(t>=0){
		x=lca[x][t];y=lca[y][t];
		while(t>=0 && lca[x][t]==lca[y][t]) t--;
	}
	return par[x];
}
void calcans(int cur){
	for(int i=0;i<vt[cur].size();i++){
		int nx=vt[cur][i];
		calcans(nx);
		sm[cur]+=sm[nx];
	}
}
int main(){
	scanf("%d", &n);
	for(int i=1;i<n;i++){
		int x,y;scanf("%d%d", &x, &y);x--;y--;
		v[x].push_back(y);v[y].push_back(x);
		lx[i]=x;ly[i]=y;
	}
	memset(vis,false,sizeof(vis));
	par[0]=-1;
	buildtree(0,0);
	for(int i=0;i<n;i++) lca[i][0]=par[i];
	for(int k=1;k<19;k++){
		for(int i=0;i<n;i++){
			if (lca[i][k-1]!=-1) lca[i][k]=lca[lca[i][k-1]][k-1];
			else lca[i][k]=-1;
		}
	}
	scanf("%d", &m);
	memset(sm, 0, sizeof(sm));
	for(int c=0;c<m;c++){
		int x,y;scanf("%d %d", &x, &y);x--;y--;
		int z = findlca(x,y);
		sm[z]-=2;sm[x]+=1;sm[y]+=1;
	}
	calcans(0);
	if (par[ly[1]]==lx[1]) printf("%d", sm[ly[1]]);
	else printf("%d", sm[lx[1]]);
	for(int i=2;i<n;i++){
		if (par[ly[i]]==lx[i]) printf(" %d", sm[ly[i]]);
		else printf(" %d", sm[lx[i]]);
	}puts("");
	return 0;
}
