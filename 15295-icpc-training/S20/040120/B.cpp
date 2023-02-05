#include <iostream>
#include <vector>
using namespace std;
int absi(int x){return x<0?-x:x;}
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
int lca(int x, int y){
	if (d[x]>d[y]){
		return lca(y, x);
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
	if (x==y) return x;
	k=0;
	while(db[x][k]!=db[y][k]) k++;
	k--;
	while(k>=0){
		x=db[x][k];y=db[y][k];
		while(k>=0 && db[x][k]==db[y][k]) k--;
	}
	return db[x][0];
}
int query(int x, int y, int z){
	int xy=lca(x, y);
	int yz=lca(y, z);
	int zx=lca(z, x);
	// cout<<xy<<" "<<yz<<" "<<zx<<endl;
	if (xy==yz){
		return (d[z]-d[zx])+(d[x]-d[zx])+(d[y]-d[xy])+absi(d[zx]-d[xy]);
	}
	if (yz==zx){
		return (d[x]-d[xy])+(d[y]-d[xy])+(d[z]-d[yz])+absi(d[xy]-d[yz]);
	}
	if (zx==xy){
		return (d[y]-d[yz])+(d[z]-d[yz])+(d[x]-d[zx])+absi(d[yz]-d[zx]);
	}
	return -1;
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
		int x, y, z;cin>>x>>y>>z;x--;y--;z--;
		cout<<query(x, y, z)<<endl;
	}
	return 0;
}
