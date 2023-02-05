#include <iostream>
#include <vector>
using namespace std;
int n,q;
vector<vector<int>> v;
vector<int> d;
vector<int> p;
void build_tree(int cur, int prev, int dep){
	p[cur]=prev;
	d[cur]=dep;
	for(auto& nxt: v[cur]){
		if (nxt==prev) continue;
		build_tree(nxt, cur, dep+1);
	}
	return;
}
vector<vector<int>> db;
bool query(int x, int y){
	if (d[x]>d[y]){
		return false;
	}
	int k=0,s=1;
	while(d[x]+s<=d[y]){
		k++;s<<=1;
	}
	k--;s>>=1;
	while(k>=0){
		y=db[y][k];
		while(k>=0 && d[x]+s>d[y]){
			k--;s>>=1;
		}
	}
	if (x==y) return true;
	else return false;
}
int main(){
	cin>>n>>q;
	v.resize(n);
	p.resize(n);
	d.resize(n);
	db.resize(n);
	for(int i=1;i<n;i++){
		int x,y;cin>>x>>y;x--;y--;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	build_tree(0, 0, 0);
	for(int i=0;i<n;i++) db[i].push_back(p[i]);
	for(int k=1;k<20;k++){
		for(int i=0;i<n;i++){
			p[i]=db[db[i].back()].back();
		}
		for(int i=0;i<n;i++) db[i].push_back(p[i]);
	}
	for(int T=0;T<q;T++){
		int x, y;cin>>x>>y;x--;y--;
		if (query(x,y)){
			cout<<"YES"<<endl;
		}else{
			cout<<"NO"<<endl;
		}
	}
	return 0;
}
