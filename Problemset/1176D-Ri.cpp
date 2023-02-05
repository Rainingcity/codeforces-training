/*
 * Codeforces 1176D
 * Recover it!
 */

#include <cstdio>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
int n;
int f[2800000];
vector<int> pm;
vector<int> ans;
bool cmp(int x, int y){return x>y;}
bool (*bigger)(int, int) = cmp;
multiset<int, bool(*)(int, int)> dat (bigger);
int main(){
	for(int i=2;i<=2750131;i++){
		if (!f[i]) pm.push_back(i);
		for(int j=0;j<pm.size();j++){
			if (pm[j]*i>2750131) break;
			f[pm[j]*i]=i;
			if (i%pm[j]==0) break;
		}
	}
	scanf("%d", &n);
	for(int i=0;i<2*n;i++){
		int x;scanf("%d", &x);
		dat.insert(x);
	}
	auto it = dat.begin();
	while(dat.size()!=0){
		it=dat.begin();
		int cur = (*it);
		dat.erase(it);
		if (f[cur]){
			ans.push_back(cur);
			dat.erase(dat.find(f[cur]));
		}else{
			int pos = (lower_bound(pm.begin(), pm.end(), cur) - pm.begin()) + 1;
			ans.push_back(pos);
			dat.erase(dat.find(pos));
		}
	}
	printf("%d", ans[0]);
	for(int i=1;i<n;i++) printf(" %d", ans[i]);
	puts("");
	return 0;
}
