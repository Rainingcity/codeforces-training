#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int n;
vector<vector<int>> v;
vector<bool> vis;
bool fnd(int cur, int x){
	int l=0, r=v[cur].size();
	while(l<r){
		int mid=(l+r)/2;
		if (v[cur][mid]==x) return true;
		if (v[cur][mid]<x) l=mid+1;
		else r=mid;
	}
	return false;
}
int main(){
	cin>>n;
	v.resize(n);
	vis.resize(n);
	for(int i=1;i<n;i++){
		int x,y;cin>>x>>y;x--;y--;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	for(int i=0;i<n;i++){
		sort(v[i].begin(),v[i].end());
	}
	int st;cin>>st;st--;
	queue<int> q;
	q.push(st);
	if (st!=0){
		puts("No");
		return 0;
	}
	vis[st]=1;
	bool F=1;
	for(int i=1;i<n;){
		if (q.empty()){
			F=0;
			break;
		}
		int cur=q.front();q.pop();
		int input_size=v[cur].size()-1;
		if (cur==st) input_size++;
		for(int j=0;j<input_size && i<n;i++, j++){
			int x;cin>>x;x--;
			if (vis[x] || !fnd(cur,x)){
				F=0;break;
			}
			q.push(x);
			vis[x]=1;
		}
		if (!F) break;
	}
	if (F) puts("Yes");
	else puts("No");
}
