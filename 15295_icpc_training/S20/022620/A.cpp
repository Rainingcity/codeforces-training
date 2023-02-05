#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int n,m;
vector<vector<int>> v;
vector<int> vis;
priority_queue<int> q;
vector<int> ans;
int main(){
	cin>>n>>m;
	vis.resize(n);
	v.resize(n);
	for(int i=0;i<m;i++){
		int x,y;cin>>x>>y;x--;y--;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	q.push(0);
	vis[0]=2;
	while(!q.empty()){
		int cur=-q.top();q.pop();
		// cout<<"cur: "<<cur<<endl;
		vis[cur]=1;
		ans.push_back(cur);
		for(auto& nxt: v[cur]){
			if (vis[nxt]) continue;
			q.push(-nxt);
			vis[nxt]=2;
		}
	}
	cout<<1;
	for(int i=1;i<ans.size();i++){
		cout<<" "<<ans[i]+1;
	}cout<<endl;
	return 0;
}
