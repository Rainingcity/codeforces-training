/*
 * Codeforces 1172B
 * Nauuo and Circle
 */

#include <cstdio>
#include <vector>
using namespace std;
typedef long long ll;
const ll MOD = 998244353;
int n;
vector<int> v[200100];
bool vis[200100];
int num_child[200100];
int sz_subtree[200100];
ll fct[200100];
ll ans;

void decide_par(int cur){
	vis[cur]=1;
	sz_subtree[cur]=1;
	for(int i=0;i<v[cur].size();i++){
		int nxt = v[cur][i];
		if (vis[nxt]) continue;
		num_child[cur]++;
		fct[cur] = (fct[cur]*(ll)num_child[cur]) % MOD;
		decide_par(nxt);
		sz_subtree[cur]+=sz_subtree[nxt];
	}
}

int main(){
	scanf("%d", &n);
	for(int i=0;i<n;i++) fct[i]=1;
	for(int i=1;i<n;i++){
		int x,y;scanf("%d%d", &x, &y);x--;y--;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	decide_par(0);
	ans = (n * fct[0]) % MOD;
	for(int i=1;i<n;i++){
		ans = (ans * (((ll)(num_child[i]+1) * fct[i]) % MOD)) % MOD;
	}
	printf("%d\n", (int)ans);
}
