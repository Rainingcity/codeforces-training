#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>
using namespace std;
typedef pair<int,int> pii;
int n,m,d;
vector<pii> v;
vector<int> ans;
int main(){
	cin>>n>>m>>d;
	ans.clear();
	ans.resize(n);
	v.clear();
	for(int i=0;i<n;i++){
		int x;cin>>x;
		v.push_back(make_pair(x,i));
	}
	sort(v.begin(), v.end());
	priority_queue<pii> q;
	while(!q.empty()) q.pop();
	int cur_days=1;
	q.push(make_pair(0,1));
	for(int i=0;i<n;i++){
		pii t=q.top();q.pop();
		if (v[i].first<-t.first){
			cur_days++;
			q.push(t);
			q.push(make_pair(-(v[i].first+d+1), cur_days));
			ans[v[i].second]=cur_days;
		}else{
			q.push(make_pair(-(v[i].first+d+1), t.second));
			ans[v[i].second]=t.second;
		}
	}
	cout<<cur_days<<endl<<ans[0];
	for(int i=1;i<n;i++) cout<<" "<<ans[i];
	cout<<endl;
	return 0;
}
