#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <utility>
#include <cmath>
using namespace std;
typedef long long ll;
typedef pair<int,ll> pil;
const ll MX=1e15;

int n,m;
unordered_map<int,ll> v[110];
priority_queue<pil> pq{};
vector<ll> dist{};
vector<pair<int,int>> sp{};
vector<bool> vis{};

bool find_path(int cur){
	if (cur==n-1){
		return true;
	}
	vis[cur]=true;
	for(auto& [nxt, weight]: v[cur]){
		if (weight!=dist[nxt]-dist[cur]) continue;
		bool ret = find_path(nxt);
		if (ret){
			sp.push_back(make_pair(cur, nxt));
			return true;
		}
	}
	return false;
}

void dijkstra(){
	dist[0]=0;
	pq.push(make_pair(0,0));
	while(!pq.empty()){
		pil tp = pq.top();pq.pop();
		int cur = tp.first;
		if (dist[cur]!=-tp.first) continue;
		for(auto& [nxt, weight]: v[cur]){
			if (dist[nxt]<dist[cur]+weight) continue;
			dist[nxt] = dist[cur]+weight;
			pq.push(make_pair(-dist[nxt], nxt));
		}
	}
	return;
}

int main(){
	cin>>n>>m;
	dist.resize(n,MX);
	vis.resize(n);
	for(int i=0;i<m;i++){
		int x,y;ll w;
		cin>>x>>y>>w;x--;y--;
		v[x][y]=w;
		v[y][x]=w;
	}
	dijkstra();
	ll pre_ans = dist[n-1];
	find_path(0);
	ll ans = pre_ans;
	for(int i=0;i<sp.size();i++){
		v[sp[i].first][sp[i].second]*=2;
		v[sp[i].second][sp[i].first]*=2;
		dist.clear();
		dist.resize(n,MX);
		dijkstra();
		ans=max(ans, dist[n-1]);
		v[sp[i].first][sp[i].second]/=2;
		v[sp[i].second][sp[i].first]/=2;
	}
	cout<<ans-pre_ans<<endl;
	return 0;
}
