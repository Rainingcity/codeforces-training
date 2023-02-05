#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
typedef pair<int, int> pii;
int mini(int x, int y){return x<y?x:y;}
int maxi(int x, int y){return x<y?y:x;}

int n,q;

class seg_tree{
private:
	vector<int> v;
	vector<int> dat;
	int N;

	int build(int idx, int l, int r){
		if (l==r){
			v[idx]=dat[l];
			return dat[l];
		}
		int mid = (l+r)>>1;
		return v[idx]=mini(build(idx*2, l, mid), build(idx*2+1, mid+1, r));
	}

	void set(int idx, int l, int r, int x, int tar){
		if (l==r){
			v[idx]=tar;
			dat[x]=tar;
			return;
		}
		int mid = (l+r)>>1;
		if (x<=mid) set(idx*2, l, mid, x, tar);
		else set(idx*2+1, mid+1, r, x, tar);
		v[idx]=mini(v[idx*2], v[idx*2+1]);
		return;
	}

	int get(int idx, int l, int r, int tl, int tr){
		if (l==tl && r==tr){
			return v[idx];
		}
		int mid = (l+r)>>1;
		if (tr<=mid) return get(idx*2, l, mid, tl, tr);
		else if (tl>mid) return get(idx*2+1, mid+1, r, tl, tr);
		else return mini(get(idx*2, l, mid, tl, mid), get(idx*2+1, mid+1, r, mid+1, tr));
	}
public:
	seg_tree(int _N, vector<int>& data):N(_N){
		v.clear();
		v.resize(5*N);
		dat.clear();
		dat.resize(N);
		for(int i=0;i<N;i++) dat[i]=data[i];
		build(1, 0, N-1);
	}

	void set(int x, int tar){
		if (mini(dat[x], tar)==dat[x]) return;
		set(1, 0, N-1, x, mini(dat[x], tar));
	}

	int get(int x){
		return dat[x];
	}

	int get(int tl, int tr){
		return get(1, 0, N-1, tl, tr);
	}
};

struct query{
	int l, r, x;
	query(){l=r=x=0;}
	query(int _l, int _r, int _x):l(_l),r(_r),x(_x){}
};

vector<query> qq;
vector<int> lb, rb;

int main(){
	cin>>n>>q;
	lb.resize(n);
	rb.resize(n);
	for(int i=0;i<n;i++) lb[i]=rb[i]=i;
	for(int i=0;i<q;i++){
		int l,r,x;cin>>l>>r>>x;
		l--;r--;x--;
		qq.push_back(query(l,r,x));
		lb[x]=mini(lb[x], l);
		rb[x]=maxi(rb[x], r);
	}
	vector<int> cnt{};
	cnt.resize(n+1);
	for(int i=0;i<n;i++){
		cnt[lb[i]]++;
		cnt[rb[i]+1]--;
	}
	for(int i=0;i<n;i++){
		cnt[i+1]+=cnt[i];
	}
	vector<pii> a{};
	for(int i=0;i<n;i++){
		a.push_back(make_pair(cnt[i], i));
	}
	sort(a.begin(), a.end());
	vector<int> ans{};
	ans.resize(n);
	for(int i=0;i<n;i++){
		ans[a[i].second] = i+1;
	}
	// cout<<ans[0];
	// for(int i=1;i<n;i++)
	// 	cout<<" "<<ans[i];
	// cout<<endl;
	seg_tree st(n, ans);
	for(int i=0;i<q;i++){
		int l=qq[i].l, r=qq[i].r, x=qq[i].x;
		if (st.get(l, r)!=ans[x]){
			// cout<<l<<" "<<r<<" "<<ans[x]<<" "<<st.get(l, r)<<endl;
			cout<<-1<<endl;
			return 0;
		}
	}
	cout<<ans[0];
	for(int i=1;i<n;i++)
		cout<<" "<<ans[i];
	cout<<endl;
	return 0;
}
