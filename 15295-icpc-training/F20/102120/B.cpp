#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;

const ll INF = numeric_limits<ll>::max();

class MaxFlow {
	struct edge {
		int to;
		ll flow, cap;
	};
	int n;
	vector<edge> edges;
	vvi g;
	vi vis;

	ll dfs(int u, int t, ll flow) {
		if (u == t)
			return flow;
		vis[u] = true;
		for (auto id : g[u]) {
			edge &e = edges[id];
			edge &rev = edges[id ^ 1];
			ll residual = e.cap - e.flow, augment = 0;
			if (vis[e.to] || residual <= 0)
				continue;
			if ((augment = dfs(e.to, t, min(flow, residual))) > 0) {
				e.flow += augment;
				rev.flow -= augment;
				return augment;
			}
		}
		return 0;
	}

public:
	// Initialise a flow network with n nodes
	MaxFlow(int n) : n(n), g(n) {}

	// Add an edge with capacity cap from node u to node v
	// Returns the index of the edge.
	int add_edge(int u, int v, ll cap) {
		g[u].push_back((int)edges.size());
		edges.push_back({v, 0, cap});
		g[v].push_back((int)edges.size());
		edges.push_back({u, 0, 0}); // Change to {u, 0, cap} for bidirectional edges
		return (int)edges.size() - 2;
	}

	// Get a reference to a specific edge: use to check flows or update capcities
	edge &get_edge(int i) { return edges[i]; }

	// Return the max flow from s to t
	ll max_flow(int s, int t) {
		for (auto &e : edges)
			e.flow = 0;
		ll flow = 0, augment = 0;
		while (vis.assign(n, 0), (augment = dfs(s, t, INF)) != 0) {
			flow += augment;
		}
		return flow;
	}

	int have_flow(int u){
		for(auto& i: g[u]){
			edge& e = get_edge(i);
			if (e.cap==1 && e.flow) return e.to;
		}
		return -1;
	}
};

vector<bool> pF (100000, false);
vector<int> primes{};
bool run(int L, int H){
	if (L==0 || H==0) return false;
	int m2=H-L+1;
	vector<vector<int>> v{};
	v.resize(m2);
	for(int cur=L;cur<=H;cur++){
		int id=cur-L,i=cur;
		for(int j=0;j<primes.size() && i>=primes[j];j++){
			if (i%primes[j]) continue;
			while(i%primes[j]==0) i/=primes[j];
			v[id].push_back(primes[j]);
			cout<<primes[j]<<" ";
		}
		cout<<endl;
	}

	unordered_set<int> pset{};
	unordered_map<int, int> loc{};
	vector<int> plist{};
	for(int i=0;i<m2;i++){
		for(int j=0;j<v[i].size();j++){
			pset.insert(v[i][j]);
		}
	}
	int i=m2+2, m1=pset.size();
	for(auto& p: pset){
		loc[p]=i;
		plist.push_back(p);
		i++;
	}

	MaxFlow mf (m1+m2+2);
	for(int i=0;i<m2;i++){
		mf.add_edge(0, i+2, 1);
		for(int j=0;j<v[i].size();j++){
			mf.add_edge(i+2, loc[v[i][j]], 1);
		}
	}
	for(int i=0;i<m1;i++) mf.add_edge(m2+i+2, 1, 1);

	int res=mf.max_flow(0, 1);
	if (res==m2){
		for(int i=2;i<m2+2;i++){
			int j=mf.have_flow(i)-m2-2;
			if (i!=2) cout<<" ";
			cout<<plist[j];
		}
		cout<<endl;
	}
	return true;
}

void gen_prime(){
	for(int i=2;i<100000;i++){
		if (!pF[i]) primes.push_back(i);
		for(int j=0;j<primes.size();j++){
			if (primes[j]*i>=100000) break;
			pF[primes[j]*i]=true;
			if (i%primes[j]==0) break;
		}
	}
}

int main(){
	gen_prime();
	int L,H;
	while(true){
		cin>>L>>H;
		if (!run(L,H)) break;
	}
	return 0;
}
