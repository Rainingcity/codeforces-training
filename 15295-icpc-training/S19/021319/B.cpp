#include<cstdio>
using namespace std;
int n;
int a[1010];
int vis[1010];
int ans[1010];
bool passed=false;
int go(int cur){
	if (!vis[cur]){
		vis[cur]=1;
		int cst=go(a[cur]);
		if (passed) ans[cur]=cst;
		else if (cur==cst){
			ans[cur]=cst;
			passed=true;
		}else ans[cur]=cur;
		vis[cur]=2;
		return cst;
	}else if (vis[cur]==2){
		passed=true;
		return ans[cur];
	}else{
		return cur;
	}
}
int main(){
	scanf("%d", &n);
	for(int i=0;i<n;i++){scanf("%d", a+i);a[i]--;}
	for(int i=0;i<n;i++){
		if (!vis[i]){
			passed=false;
			go(i);
		}
	}
	printf("%d", ans[0]+1);
	for(int i=1;i<n;i++) printf(" %d", ans[i]+1);
	puts("");
	return 0;
}
