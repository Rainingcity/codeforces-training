/*
 * Codeforces 1176C
 * Lose it!
 */

#include <cstdio>
using namespace std;
int mp[50];
int pos[10];
int n;
int main(){
	mp[4]=1;mp[8]=2;mp[15]=3;mp[16]=4;mp[23]=5;mp[42]=6;
	scanf("%d", &n);
	int ans = 0;
	pos[0]=n;
	for(int i=0;i<n;i++){
		int x;scanf("%d", &x);
		if (mp[x]==0){
			ans++;
			continue;
		}
		if (pos[mp[x]]>=pos[mp[x]-1]){
			ans++;
			continue;
		}
		pos[mp[x]]++;
	}
	for(int i=1;i<6;i++) ans += pos[i]-pos[6];
	printf("%d\n", ans);
	return 0;
}
