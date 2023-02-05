/*
 * Codeforces 1174C
 * Ehab and a Special Coloring Problem
 */

#include <cstdio>
#include <vector>
using namespace std;
const int MX = 100300;
int n;
int f[200100];
int cnt[200100];
vector<int> pm;
int main(){
	scanf("%d", &n);
	for(int i=2;i<=n;i++){
		if (!f[i]) pm.push_back(i);
		for(int j=0;j<pm.size();j++){
			if (pm[j]*i>=MX) break;
			f[pm[j]*i]=pm[j];
			if (i%pm[j]==0) break;
		}
	}
	int s=1;
	for(int i=2;i<=n;i++){
		if (!f[i]){
			cnt[i]=s++;
		}else{
			cnt[i]=cnt[f[i]];
		}
	}
	printf("%d", cnt[2]);
	for(int i=3;i<=n;i++) printf(" %d", cnt[i]);
	puts("");
	return 0;
}
