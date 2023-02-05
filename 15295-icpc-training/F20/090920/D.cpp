#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef long long ll;
int n,m,k;
ll r,c,p;
vector<ll> col;
priority_queue<ll> hrow, hcol;
int main(){
	cin>>n>>m>>k>>p;
	col.resize(m);
	for(int i=0;i<n;i++){
		ll cur_row=0;
		for(int j=0;j<m;j++){
			ll x;cin>>x;
			cur_row+=x;
			col[j]+=x;
		}
		hrow.push(cur_row);
	}
	for(int j=0;j<m;j++) hcol.push(col[j]);
	ll ans=0;
	for(int cnt=0;cnt<k;cnt++){
		ll cur_row=hrow.top(), cur_col=hcol.top();
		cur_row-=c*p;
		cur_col-=r*p;
		if (cur_row<cur_col || (cur_row==cur_col && n<m)){
			ans+=cur_col;
			cur_col=hcol.top();
			hcol.pop();
			hcol.push(cur_col-n*p);
			c++;
		}else{
			ans+=cur_row;
			cur_row=hrow.top();
			hrow.pop();
			hrow.push(cur_row-m*p);
			r++;
		}
	}
	cout<<ans<<endl;
	return 0;
}
