#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MOD = 1e9+7;
vector<int> v;

ll inv(int x){
	if (x==1) return 1;
	ll t = MOD/x+1;
	return (t*inv(t*x-MOD))%MOD;
}

ll fastpow (ll x, ll y){
	if (y==0) return 1;
	if (y==1) return x;
	ll k = fastpow (x, y>>1);
	k = (k*k)%MOD;
	if (y&1) return (k*x)%MOD;
	else return k;
}

bool nprime[10010];
vector<int> p;int pn;

int calc(int num, int c){
	v.clear();
	int tnum=num;
	for(int i=0;i<pn && tnum!=1;i++){
		if (tnum%p[i]==0){
			int cnt=0;
			while(tnum%p[i]==0){
				cnt++;tnum/=p[i];
			}
			v.push_back(cnt);
		}
	}
	if (tnum!=1) v.push_back(1);
	sort(v.begin(),v.end());
	ll ans = fastpow(2, c-1);
	ll cur = 1, curn = 0;
	for(int i=0;i<v.size();i++){
		int x=v[i];
		while(curn<x){
			curn++;
			cur = (cur*(c+curn-1))%MOD;
			cur = (cur*inv(curn))%MOD;
		}
		ans = (ans*cur)%MOD;
	}
	return (int)ans;
}
int main(){
	for(int i=2;i<2000;i++){
		if (!nprime[i]) p.push_back(i);
		for(int j=0;j<p.size();j++){
			if (p[j]*i<=5000) nprime[p[j]*i]=true;
			if (i%p[j]==0) break;
		}
	}
	pn=p.size();
	int cnt;scanf("%d", &cnt);
	while(cnt--){
		int x,y;scanf("%d%d", &x, &y);
		printf("%d\n", calc(x,y));
	}
}
