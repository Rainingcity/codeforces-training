#include<cstdio>
#include<set>
using namespace std;
set<int> s;
int ans[300100];
int main(){
	int n,m;scanf("%d%d", &n, &m);
	for(int i=0;i<n;i++) s.insert(i+1);
	for(int i=0;i<m;i++){
		int l,r,w;scanf("%d%d%d", &l, &r, &w);
		set<int>::iterator it=s.lower_bound(l);
		while(it!=s.end() && (*it)<=r){
			int cur = *it;
			s.erase(it);
			if (cur!=w) ans[cur]=w;
			it=s.lower_bound(l);
		}
		s.insert(w);
	}
	printf("%d", ans[1]);
	for(int i=2;i<=n;i++) printf(" %d", ans[i]);
	puts("");
	return 0;
}
