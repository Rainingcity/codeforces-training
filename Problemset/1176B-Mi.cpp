/*
 * Codeforces 1176B
 * Merge it!
 */

#include <cstdio>
using namespace std;
int mini(int x, int y){return x<y?x:y;}

int n;
int cnt[3];
void solve(){
	scanf("%d", &n);
	cnt[0]=cnt[1]=cnt[2]=0;
	for(int i=0;i<n;i++){
		int x;scanf("%d", &x);
		cnt[x%3]++;
	}
	int ans = mini(cnt[1], cnt[2]);
	cnt[1]-=ans;cnt[2]-=ans;
	ans += cnt[0];
	ans += (cnt[1]/3)+(cnt[2]/3);
	printf("%d\n", ans);
	return;
}

int main(){
	int q;scanf("%d", &q);
	while(q--){
		solve();
	}
}
