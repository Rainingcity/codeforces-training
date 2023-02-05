#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int n;
vector<int> vis;
vector<int> par;

int dfs(int cur){
	if (vis[cur]) return vis[cur];
	if (par[cur]==-1) return vis[cur]=1;
	return vis[cur]=dfs(par[cur])+1;
}

int main(){
	cin>>n;
	vis.resize(n);
	for(int i=0;i<n;i++){
		int x;cin>>x;if (x!=-1) x--;
		par.push_back(x);
	}

	int ans=0;
	for(int i=0;i<n;i++){
		if (!vis[i]) ans=max(ans, dfs(i));
	}

	cout<<ans<<endl;
	return 0;
}
