#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
typedef int cmp_fn(int, int);
int mini(int x, int y){return x>y?y:x;}
int maxi(int x, int y){return x<y?y:x;}
typedef pair<int, int> pii;

int n,q;

class seg_tree{
private:
	vector<int> v;
	vector<int> dat;
	int N;
	cmp_fn* fn;

	int build(int idx, int l, int r){
		if (l==r){
			v[idx]=l;
			dat[l]=l;
			return l;
		}
		int mid = (l+r)>>1;
		return v[idx]=fn(build(idx*2, l, mid), build(idx*2+1, mid+1, r));
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
		v[idx]=fn(v[idx*2], v[idx*2+1]);
		return;
	}

	int get(int idx, int l, int r, int tl, int tr){
		if (l==tl && r==tr){
			return v[idx];
		}
		int mid = (l+r)>>1;
		if (tr<=mid) return get(idx*2, l, mid, tl, tr);
		else if (tl>mid) return get(idx*2+1, mid+1, r, tl, tr);
		else return fn(get(idx*2, l, mid, tl, mid), get(idx*2+1, mid+1, r, mid+1, tr));
	}
public:
	seg_tree(int _N, cmp_fn* _fn):N(_N), fn(_fn){
		v.clear();
		v.resize(5*N);
		dat.clear();
		dat.resize(N);
		build(1, 0, N-1);
	}

	void set(int x, int tar){
		if (fn(dat[x], tar)==dat[x]) return;
		set(1, 0, N-1, x, fn(dat[x], tar));
	}

	int get(int x){
		return dat[x];
	}

	int get(int tl, int tr){
		return get(1, 0, N-1, tl, tr);
	}
};

int main(){
	cin>>n>>q;
	seg_tree lb(n, &mini);
	seg_tree rb(n, &maxi);

	for(int i=0;i<q;i++){
		int l,r,x;cin>>l>>r>>x;
		l--;r--;x--;
		lb.set(x, l);
		rb.set(x, r);
	}
	for(int i=0;i<n;i++){
		int lbi=lb.get(i), rbi=rb.get(i);
		if (lbi==rbi) continue;
		if (i<rbi && lb.get(i+1, rbi)<=i){
			cout<<-1<<endl;
			return 0;
		}
		if (i>lbi && rb.get(lbi, i-1)>=i){
			cout<<-1<<endl;
			return 0;
		}
	}
	// for(int i=0;i<n;i++) if (i<rb.get(i)) cout<<i<<" "<<lb.get(i+1, rb.get(i))<<endl;
	// cout<<endl;
	// for(int i=0;i<n;i++) if (i>lb.get(i)) cout<<i<<" "<<rb.get(lb.get(i), i-1)<<endl;
	// cout<<endl;

	vector<int> cnt{};
	cnt.resize(n+1);
	for(int i=0;i<n;i++){
		cnt[lb.get(i)]++;
		cnt[rb.get(i)+1]--;
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
	cout<<ans[0];
	for(int i=1;i<n;i++)
		cout<<" "<<ans[i];
	cout<<endl;
	return 0;
}
