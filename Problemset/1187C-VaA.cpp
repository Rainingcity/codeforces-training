/*
 * Codeforces 1187C
 * Vasya and Array
 */

#include <cstdio>
#include <vector>
using namespace std;
int n,m;
int fa[1010];
int ans[1010];
struct seg{
	int l,r;
	seg()=default;
	seg(int x, int y): l(x), r(y){}
};
vector<seg> v;
int main(){
	scanf("%d%d", &n, &m);
	for(int i=0;i<m;i++){
		int op, x, y;scanf("%d%d%d", &op, &x, &y);x--;y--;
		if (op==1){
			fa[x]++;fa[y]--;
		}else{
			v.push_back(seg(x, y));
		}
	}
	int cur=0;
	for(int i=0;i<n;i++){
		if (cur>0){
			ans[i]=n+i;
		}
		cur+=fa[i];
	}
	for(int i=n-1;i>=0;i--) if (!ans[i]) ans[i]=n-i;
	for(auto& c: v){
		bool f=0;
		for(int j=c.l;j<c.r && !f;j++){
			if (ans[j]>ans[j+1]) f=1;
		}
		if (!f){
			puts("NO");
			return 0;
		}
	}
	puts("YES");
	printf("%d", ans[0]);
	for(int i=1;i<n;i++){
		printf(" %d", ans[i]);
	}
	puts("");
	return 0;
}
