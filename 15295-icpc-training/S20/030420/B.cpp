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
//	  G.add_edge(u, v, cap)
//	    Adds an edge from u -> v with capacity. Returns the index
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

int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
int n,m;
int enc(int x, int y){
  return x*m+y;
}
bool valid(int x,int y){
  return 0<=x && x<n && 0<=y && y<m;
}
vector<string> graph;
int main(){
  cin>>n>>m;
  MaxFlow mf (2+2*n*m);
  int lvl2=1+n*m;
  int dest=2*n*m+1;
  for(int i=0;i<n;i++){
    string s;cin>>s;
    graph.push_back(s);
  }
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      int id1=enc(i,j);
      if (graph[i][j]=='x'){
        mf.add_edge(0,id1+1,0);
        mf.add_edge(lvl2+id1,dest,0);
        continue;
      }else{
        mf.add_edge(0,id1+1,1);
        mf.add_edge(lvl2+id1,dest,1);
      }
      for(int k=0;k<4;k++){
        int ni=i+dx[k],nj=j+dy[k];
        int id2=enc(ni,nj);
        if (!valid(ni, nj)) continue;
        if (graph[ni][nj]=='x') continue;
        mf.add_edge(id1+1,lvl2+id2,1);
        mf.add_edge(id2+1,lvl2+id1,1);
      }
    }
  }
  cout<<mf.max_flow(0,dest)/2<<endl;
  return 0;
}
