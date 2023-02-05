#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;
typedef pair<int,int> pii;
const int MX = 3000000;

int n,m;
vector<vector<pii>> v{};
priority_queue<pii> pq{};
vector<int> dist{};
int main(){
	cin>>m>>n;
	v.resize(n);
	dist.resize(n,MX);
	for(int i=0;i<m;i++){
		int x,y,w;cin>>x>>y>>w;x--;y--;
		v[x].push_back(make_pair(y,w));
		v[y].push_back(make_pair(x,w));
	}
	dist[n-1]=0;
	pq.push(make_pair(0, n-1));
	while(!pq.empty()){
		pii tp = pq.top();pq.pop();
		int cur = tp.second;
		// cout<<tp.first<<" "<<tp.second<<endl;
		if (dist[cur]!=-tp.first) continue;
		if (cur==0) break;
		for(int i=0;i<v[cur].size();i++){
			int nxt = v[cur][i].first;
			if (dist[nxt]<=dist[cur]+v[cur][i].second) continue;
			dist[nxt]=dist[cur]+v[cur][i].second;
			pq.push(make_pair(-dist[nxt], nxt));
		}
	}
	cout<<dist[0]<<endl;
	return 0;
}
