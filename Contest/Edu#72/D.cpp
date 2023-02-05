#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>
#include <utility>
using namespace std;
typedef pair<int, int> pii;
int n,m;
vector<vector<pii>> v;
set<int> s;
bool col[5010];
bool vis[5010];
void dfs(int cur){
	s.insert(cur);
	vis[cur]=1;
	for(int i=0;i<v[cur].size();i++){
		int nxt=v[cur][i].first;
		int edge=v[cur][i].second;
		if (vis[nxt]){
			if (s.find(nxt)==s.end()) col[edge]=0;
			else col[edge]=1;
		}else{
			dfs(nxt);
		}
	}
	s.erase(cur);
	return;
}
int main(){
	cin>>n>>m;
	v.resize(n);
	for(int i=0;i<m;i++){
		int x,y;cin>>x>>y;x--;y--;
		v[x].push_back(make_pair(y, i));
	}
	for(int i=0;i<n;i++){
		if (!vis[i]) dfs(i);
	}
	int k=1;
	for(int i=0;i<m;i++){
		if (col[i]) k=2;
	}
	cout<<k<<endl;
	for(int i=0;i<m;i++){
		if (i) cout<<" ";
		if (col[i]) cout<<2;
		else cout<<1;
	}
	cout<<endl;
	return 0;
}
