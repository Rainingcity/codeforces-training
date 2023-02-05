#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
const ll MOD=1e9+7;
int n,m;
vector<vector<int>> v;
vector<bool> vis;
bool dfs(int cur, ll& cntn, ll& cntm){
	vis[cur]=true;cntn++;cntm+=v[cur].size();
	bool ret=false;
	for(auto nxt: v[cur]){
		if (vis[nxt]){
			ret=true;
		}else dfs(nxt, cntn, cntm);
	}
	return ret;
}
int main(){
	cin>>n>>m;v.resize(n);vis.resize(n, false);
	for(int i=0;i<m;i++){
		int x,y;cin>>x>>y;x--;y--;
		v[x].push_back(y);v[y].push_back(x);
	}
	if (m>n){
		cout<<0<<endl;
		return 0;
	}
	ll ans=1;
	for(int i=0;i<n;i++){
		if (!vis[i]){
			ll cntn=0, cntm=0;
			bool F=dfs(i,cntn, cntm);
			cntm>>=1;
			if (cntm>cntn){
				cout<<0<<endl;
				return 0;
			}
			if (F){
				ans=(ans<<1)%MOD;
			}else{
				ans=(ans*cntn)%MOD;
			}
		}
	}
	cout<<ans<<endl;
}
