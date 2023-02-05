#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
const ll MOD=1e9+7;
vector<int> f,p;
vector<bool> phi;
int n,m;
int main(){
	cin>>n>>m;
	f.resize(n+1);
	phi.resize(n+1);
	for(int i=2;i<=n;i++){
		if (!f[i]) p.push_back(i);
		for(int j=0;j<p.size();j++){
			if (i*p[j]>n) break;
			f[i*p[j]]=p[j];
			if (i%p[j]==0) break;
		}
	}
	ll ans=1;
	for(int i=2;i<=m;i++){
		int c=i;
		while (f[c]!=0){
			if (phi[f[c]]) ans=(ans*(ll)f[c])%MOD;
			else{
				phi[f[c]]=true;
				ans=(ans*(ll)(f[c]-1))%MOD;
			}
			c/=f[c];
		}
		if (phi[c]) ans=(ans*(ll)c)%MOD;
		else{
			phi[c]=true;
			ans=(ans*(ll)(c-1))%MOD;
		}
	}
	for(int i=m+1;i<=n;i++){
		ans=(ans*(ll)i)%MOD;
	}
	cout<<ans<<endl;
	return 0;
}
