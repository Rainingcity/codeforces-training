#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <utility>
using namespace std;
typedef long long ll;
typedef pair<ll,int> pii;
const ll INF=1e16;
class SegTree{
private:
	vector<int> vid;
	vector<ll> v;
	vector<ll> laz;
	int n;
	pii getmin(int id1, int id2){
		if (v[id1]<v[id2]){
			return make_pair(v[id1], vid[id1]);
		}else{
			return make_pair(v[id2], vid[id2]);
		}
	}
	void push(int id){
		v[id]-=laz[id];
		laz[id<<1]+=laz[id];
		laz[(id<<1)+1]+=laz[id];
		laz[id]=0;
	}
	void build(int id, int l, int r, vector<ll>& dat){
		if (l+1==r){
			v[id]=dat[l];
			vid[id]=l;
			return;
		}
		int mid=(l+r)>>1;
		build((id<<1), l, mid, dat);
		build((id<<1)+1, mid, r, dat);
		auto t=getmin((id<<1), (id<<1)+1);
		v[id]=t.first;vid[id]=t.second;
		return;
	}
	void query(int id, int l, int r){
		if (l+1==r){
			v[id]-=laz[id];
			laz[id]=0;
			return;
		}
		push(id);
		if (v[id]!=0) return;
		int mid=(l+r)>>1;
		query(id<<1, l, mid);
		query((id<<1)+1, mid, r);
		auto t=getmin((id<<1), (id<<1)+1);
		v[id]=t.first;vid[id]=t.second;
	}
	void update(int id, int l, int r, int tl, int tr, ll x){
		if (l==tl && r==tr){
			laz[id]+=x;
			return;
		}
		push(id);
		int mid=(l+r)>>1;
		if (tl<mid) update((id<<1), l, mid, tl, min(tr, mid), x);
		if (tr>mid) update((id<<1)+1, mid, r, max(tl, mid), tr, x);
		auto t=getmin((id<<1), (id<<1)+1);
		v[id]=t.first;vid[id]=t.second;
	}
public:
	SegTree(int N, vector<ll>& dat){
		n=N;
		v.resize(5*N);
		laz.resize(5*N);
		vid.resize(5*N);
		build(1, 0, N, dat);
	}
	int findz(){
		query(1, 0, n);
		return vid[1];
	}
	void update(int tl, int tr, ll x){
		if (tl==tr) return;
		update(1, 0, n, tl, tr, x);
	}
};
int n;
vector<ll> v;
vector<int> ans;
int main(){
	cin>>n;
	ans.resize(n);
	for(int i=0;i<n;i++){
		ll x;cin>>x;v.push_back(x);
	}
	SegTree s(n,v);
	for(int c=1;c<=n;c++){
		int k=s.findz();
		if (k<0) return 1;
		ans[k]=c;
		s.update(k, k+1, -INF);
		s.update(k+1, n, c);
	}
	for(int i=0;i<n;i++){
		if (i) cout<<" ";
		cout<<ans[i];
	}
	cout<<endl;
	return 0;
}
