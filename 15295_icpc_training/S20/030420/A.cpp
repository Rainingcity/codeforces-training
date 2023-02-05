// Maximum flow using Ford-Fulkerson
//
// Author      : Daniel Anderson
// Date        : 28-08-2016
//
// Usage:
//    MaxFlow G(n)
//      Create a flow network G with n nodes
//
//    G.max_flow(int s, int t)
//      Returns the maximum flow s -> t
//
//    G.add_edge(u, v, cap)
//      Adds an edge from u -> v with capacity. Returns the index
//      of the edge.
//
//    G.get_edge(i)
//      Returns a reference to the i'th edge. Use to check flows
//      or update capacities
//
//  Time Complexity: O(Ef), where f is the maximum flow and E
//    is the number of edges in the network.

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
};

int n,m;
vector<int> p;
int main(){
    cin>>n>>m;
    MaxFlow mf (n+m+2);
    int sum=0;
    for(int i=0;i<n;i++){
        int x;cin>>x;
        mf.add_edge(0,i+1,x);
        p.push_back(x);
        sum+=x;
    }
    for(int j=0;j<m;j++){
        int x;cin>>x;
        mf.add_edge(n+j+1,n+m+1,x);
    }
    for(int i=0;i<n;i++){
        int k;cin>>k;
        for(int j=0;j<k;j++){
            int t;cin>>t;
            mf.add_edge(i+1,n+t,p[i]);
        }
    }
    if (mf.max_flow(0, n+m+1)==sum){
        cout<<"PARTY"<<endl;
    }else{
        cout<<"NO"<<endl;
    }
    return 0;
}
