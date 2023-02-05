#include <iostream>
#include <vector>
#include <utility>
#include <queue>
using namespace std;
typedef long long ll;
ll mini(ll x, ll y){return x<y?x:y;}
ll absi(ll x){return x<0?-x:x;}
const ll inf = 1e12;
int n,m;
vector<vector<pair<int,ll>>> v;
void dijkstra(vector<ll>& dist, int st){
	dist[st]=0;
	priority_queue<pair<ll, int>> pq{};
	pq.push(make_pair(0, st));
	while(!pq.empty()){
		auto [val, cur]=pq.top();pq.pop();
		// cout<<val<<" "<<cur<<endl;
		if (val!=-dist[cur]) continue;
		// cout<<"YES"<<endl;
		for(auto& [nxt, weight]: v[cur]){
			if (-val+weight>=dist[nxt]) continue;
			dist[nxt]=-val+weight;
			pq.push(make_pair(val-weight, nxt));
		}
	}
	return;
}
vector<ll> dis1,dis2;
int main(){
	cin>>n>>m;
	v.resize(n);
	dis1.resize(n, inf);
	dis2.resize(n, inf);
	for(int i=0;i<n;i++) v[i].clear();
	for(int i=0;i<m;i++){
		int u1,u2;ll w;cin>>u1>>u2>>w;u1--;u2--;
		v[u1].push_back(make_pair(u2,w));
		v[u2].push_back(make_pair(u1,w));
	}
	dijkstra(dis1, 0);
	dijkstra(dis2, n-1);
	// for(int i=0;i<n;i++) cout<<dis1[i]<<" "<<dis2[i]<<endl;
	ll mn = inf;
	for(int i=0;i<n;i++){
		mn=mini(mn, absi(dis1[i]-dis2[i]));
	}
	cout<<mn<<endl;
	return 0;
}
