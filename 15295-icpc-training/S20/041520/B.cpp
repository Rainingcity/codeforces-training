#include <iostream>
#include <vector>
using namespace std;
const int MAXN = 1e7+10;
const int MAXP = 4000;
int n;
vector<int> f;
vector<int> p;
vector<int> mu;
int main(){
	cin>>n;
	mu.resize(n+1);f.resize(MAXN);
	for(int i=2;i<=n;i++){
		if (f[i]==0){
			p.push_back(i);
			f[i]=i;
		}
		for(int j=0;j<p.size();j++){
			if (i*p[j]>=MAXN) break;
			f[i*p[j]]=p[j];
			if (i%p[j]==0) break;
		}
	}
	int ans=1;
	mu[1]=1;
	for(int i=2;i<=n;i++){
		if (f[i]==0) mu[i]=-1;
		else if (f[i/f[i]]==f[i]) mu[i]=0;
		else mu[i]=-mu[i/f[i]];
		ans+=mu[i];
	}
	cout<<ans<<endl;
	return 0;
}
