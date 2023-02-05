#include<cstdio>
#include<vector>
using namespace std;
vector<int> v[100100];
int n;
bool vis[100100];

double dfs(int i, int dep){
	vis[i]=true;
	double ans = 1.0/dep;
	for(int j=0;j<v[i].size();j++){
		if (vis[v[i][j]]) continue;
		ans += dfs(v[i][j], dep+1);
	}
	return ans;
}

int main(){
	scanf("%d", &n);
	for(int i=1;i<n;i++){
		int x,y;scanf("%d%d", &x, &y);x--;y--;
		v[x].push_back(y);v[y].push_back(x);
	}
	printf("%lf\n", dfs(0,1));
	return 0;
}
