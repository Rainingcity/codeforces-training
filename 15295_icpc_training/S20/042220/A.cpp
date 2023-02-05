#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int n,m;
vector<vector<int>> v;
vector<int> dist;
queue<int> q;
int bfs(int st, int ed){
	while(!q.empty()) q.pop();
	q.push(0);
	while(!q.empty()){
		int cur=q.front();q.pop();
		if (cur==ed) return dist[cur];
		for(auto& nxt: v[cur]){
			if (dist[nxt]) continue;
			dist[nxt]=dist[cur]+1;
			q.push(nxt);
		}
	}
	return -1;
}
int main(){
	cin>>n>>m;
	dist.resize(n);
	v.resize(n);
	for(int i=0;i<m;i++){
		int x, y;cin>>x>>y;x--;y--;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	int ans=bfs(0,n-1)-1;
	cout<<ans<<endl;
}
