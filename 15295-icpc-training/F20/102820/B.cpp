#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;
vector<vector<ll>> c{};
int n;
int main(){
	cin>>n;
	c.resize(3000);
	c[0].push_back(1);
	for (int i=1;i<3000;i++){
		c[i].push_back(1);
		for(int j=1;j<i;j++){
			c[i].push_back((c[i-1][j-1]+c[i-1][j])%MOD);
		}
		c[i].push_back(1);
	}
	int cur;
	cin>>cur;
	ll ans=1;
	for(int i=1;i<n;i++){
		int nxt;cin>>nxt;
		ans=(ans*c[cur+nxt-1][nxt-1])%MOD;
		cur+=nxt;
	}
	cout<<ans<<endl;
	return 0;
}
