#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
inline int maxi(int x, int y){return x<y?y:x;}
class SegTree{
private:
	vector<int> v;
	int n;
	void build(int id, int l, int r, vector<int>& dat){
		if (l+1==r){
			v[id]=dat[l];
			return;
		}
		int mid=(l+r)>>1;
		int lid=id<<1, rid=(id<<1)+1;
		build(lid, l, mid, dat);
		build(rid, mid, r, dat);
		v[id]=maxi(v[lid], v[rid]);
	}
	int query(int id, int l, int r, int tl, int tr){
		if (l==tl && r==tr) return v[id];
		int mid=(l+r)>>1;
		if (tl<mid && tr>mid) return maxi(query(id<<1, l, mid, tl, min(tr, mid)), query((id<<1)+1, mid, r, max(tl, mid), tr));
		else if (tl<mid) return query(id<<1, l, mid, tl, min(tr, mid));
		else return query((id<<1)+1, mid, r, max(tl, mid), tr);
	}
public:
	SegTree(int N, vector<int>& dat){
		n=N;
		v.resize(5*N);
		build(1, 0, N, dat);
	}
	int get_size(){return n;}
	int query(int l, int r){
		return query(1, 0, n, l, r);
	}
};
vector<SegTree> v;
vector<int> dat{};
int n, w;
int main(){
	cin>>n>>w;
	int st=-1;
	for(int i=0;i<n;i++){
		int sz;cin>>sz;
		st=max(sz,st);
		dat.resize(sz);
		for(int j=0;j<sz;j++) cin>>dat[j];
		SegTree t(sz, dat);
		v.push_back(t);
	}
	ll stsum=0;
	for(int i=0;i<w;i++){
		ll sum=0;
		if (i>=st && i<=n-st){
			cout<<" ";
			cout<<stsum<<endl;
		}
		for(int j=0;j<n;j++){
			int sz=v[j].get_size();
			int l=max(0, i-(n-sz)), r=min(sz, i+1);
			sum+=(ll)max(0, v[j].query(l, r));
		}
		if (i==st-1) stsum=sum;
		if (i) cout<<" ";
		cout<<sum;
	}
	cout<<endl;
	return 0;
}
