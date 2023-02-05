#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <queue>
using namespace std;
typedef pair<int,int> pii;
int maxi(int x, int y){return x<y?y:x;}

int n,m,k;
vector<pii> v;
vector<int> ans;

bool cmp(pii x, pii y){
	return x.first!=y.first?x.first>y.first:x.second<y.second;
}

int try_assign(int x){
	priority_queue<pii> q;
	while(!q.empty()) q.pop();
	for(int i=0;i<m;i++) q.push(make_pair(x+k, i+1));
	for(int i=0;i<n;i++){
		pii t=q.top();q.pop();
		if (v[i].first>t.first) return -1;
		ans[v[i].second]=t.second;
		q.push(make_pair(t.first-v[i].first, t.second));
	}
	if (q.top().first>k) return 1;
	else return 0;
}

void work(){
	cin>>n>>m>>k;
	ans.clear();
	ans.resize(n);
	v.clear();
	int sum=0;
	for(int i=0;i<n;i++){
		int x;cin>>x;
		v.push_back(make_pair(x,i));
		sum+=x;
	}
	sort(v.begin(), v.end(), cmp);
	int l=0, r=sum/m;
	bool F=0;
	while(l<=r){
		int mid=(l+r)>>1;
		int j=try_assign(mid);
		// cout<<l<<" "<<r<<" "<<mid<<" "<<j<<endl;
		if (j==0){
			r=mid;
			F=1;
			break;
		}else if (j==-1) l=mid+1;
		else r=mid-1;
	}
	if (F){
		cout<<"YES"<<endl<<ans[0];
		for(int i=1;i<n;i++) cout<<" "<<ans[i];
		cout<<endl;
	}else cout<<"NO"<<endl;
}

int main(){
	int T;cin>>T;
	while(T--){
		work();
	}
	return 0;
}
