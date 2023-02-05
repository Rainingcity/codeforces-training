#include<cstdio>
#include<vector>
#include<cstring>
using namespace std;
typedef long long ll;
int n,k;
vector<int> v[50010];
vector<int> vt[50010];
bool vis[50010];
struct node{
	ll num;
	ll cntd[510];
	node(){
		num=0ll;
		memset(cntd,0,sizeof(cntd));
	}
}tr[50010];
void buildtree(int cur){
	vis[cur]=true;
	for(int i=0;i<v[cur].size();i++){
		if (vis[v[cur][i]]) continue;
		vt[cur].push_back(v[cur][i]);
		buildtree(v[cur][i]);
	}
}
void calcans(int cur){
	tr[cur].cntd[0]=1ll;
	tr[cur].num=0ll;
	for(int i=0;i<vt[cur].size();i++){
		int nx=vt[cur][i];
		calcans(nx);
		tr[cur].num+=tr[nx].num;
		for(int j=1;j<k;j++) tr[cur].num+=tr[cur].cntd[j]*tr[nx].cntd[k-j-1];
		for(int j=1;j<=k;j++) tr[cur].cntd[j]+=tr[nx].cntd[j-1];
	}
//	printf("%d:\n", cur+1);
//	for(int j=0;j<k;j++) printf("%d ", tr[cur].cntd[j]);
//	printf("%d\n", tr[cur].cntd[k]);
	tr[cur].num+=tr[cur].cntd[k];
}
int main(){
	scanf("%d%d", &n, &k);
	for(int i=1;i<n;i++){
		int x,y;scanf("%d%d", &x, &y);x--;y--;
		v[x].push_back(y);v[y].push_back(x);
	}
	memset(vis,false,sizeof(vis));
	buildtree(0);calcans(0);
	printf("%lld\n", tr[0].num);
}
