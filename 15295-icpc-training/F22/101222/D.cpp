#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <utility>
#include <cmath>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

const ll MOD = 1e9+7;

int maxi(int x, int y){return x<y?y:x;}
int mini(int x, int y){return x<y?x:y;}

int n;
vector<int> v;
vector<int> vis;

int find_circ(int i){
	if (vis[i] == -2){
		return i;
	}else if (vis[i] != 0){
		return -1;
	}
	vis[i] = -2;
	int ret = find_circ(v[i]);
	if (ret == -1){
		vis[i] = -1;
		return -1;
	}
	vis[i] = ret;
	if (i == ret) return -1;
	else return ret;
}

int main(){
	cin>>n;
	vis.resize(n);
	for(int i=0;i<n;i++){
		int x;cin>>x;x--;
		v.push_back(x);
	}
	for(int i=0;i<n;i++){
		if (!vis[i]) find_circ(i);
	}
	ll res = 1;
	for(int i=0;i<n;i++){
		if (vis[i]==-1) res = (res << 1) % MOD;
		else if (vis[i]==i){
			ll tmp = 2, it = v[i];
			while(it != i){
				tmp = (tmp << 1) % MOD;
				it = v[it];
			}
			tmp = (tmp + MOD - 2) % MOD;
			res = (res * tmp) % MOD;
		}
	}
	cout<<res<<endl;
	return 0;
}
