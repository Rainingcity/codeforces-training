#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
ll x;
vector<bool> f;
vector<int> p;
int main(){
	cin>>x;
	f.resize(100000);
	for(int i=2;i<100000;i++){
		if (!f[i]) p.push_back(i);
		for(int j=0;j<p.size();j++){
			if (i*p[j]>=100000) break;
			f[i*p[j]]=true;
			if (i%p[j]==0) break;
		}
	}
	ll ans=1;
	for(int i=0;i<p.size() && x!=1;i++){
		if (x%p[i]) continue;
		ll cur=1;
		while(x%p[i]==0){
			x/=p[i];
			cur++;
		}
		ans*=cur;
	}
	if (x!=1) ans*=2;
	cout<<ans<<endl;
	return 0;
}
