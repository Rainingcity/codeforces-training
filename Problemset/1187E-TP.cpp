/*
 * Codeforces 1187E
 * Tree Painting
 */

#include <cstdio>
#include <vector>
#include <iostream>
using namespace std;
typedef long long ll;
int n;
vector<vector<int>> v, st;
ll from_root[200100];
ll subtree_size[200100];
void get_graph(int cur, int prev = -1){
	subtree_size[cur]=1;
	for(int i=0;i<st[cur].size();i++){
		int nxt = st[cur][i];
		if (nxt==prev) continue;
		v[cur].push_back(nxt);
		get_graph(nxt, cur);
		subtree_size[cur] += subtree_size[nxt];
		from_root[cur] += from_root[nxt];
	}
	from_root[cur] += subtree_size[cur];
}
ll ans = 0;
void dfs(int cur, ll cum_ans = 0, ll cum_sz = 0){
	if (v[cur].size()==0){
		if (cum_ans+n > ans) ans = cum_ans+n;
		return;
	}
	for(int i=0;i<v[cur].size();i++){
		int nxt = v[cur][i];
		ll cur_sz = cum_sz + subtree_size[cur] - subtree_size[nxt];
		ll cur_ans = cum_ans + cum_sz + from_root[cur] - from_root[nxt] - subtree_size[nxt];
		dfs(nxt, cur_ans, cur_sz);
	}
}
int main(){
	cin>>n;
	st.resize(n);v.resize(n);
	for(int i=1;i<n;i++){
		int x, y;cin>>x>>y;
		x--;y--;
		st[x].push_back(y);
		st[y].push_back(x);
	}
	get_graph(0);
	dfs(0);
	cout<<ans<<endl;
	return 0;
}
