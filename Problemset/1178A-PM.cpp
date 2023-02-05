/*
 * Codeforces 1178A
 * Prime Minister
 */

#include <cstdio>
#include <vector>
using namespace std;
int n, sum=0, cur=0;
vector<int> ans;
int main(){
	scanf("%d", &n);
	ans.clear();
	int x;
	scanf("%d", &x);
	sum+=x, cur+=x;
	for(int i=1;i<n;i++){
		int y;scanf("%d", &y);
		if (y*2<=x){
			cur+=y;
			ans.push_back(i+1);
		}
		sum+=y;
	}
	if (cur*2>sum){
		printf("%d\n1", (int)ans.size()+1);
		for(int i=0;i<ans.size();i++){
			printf(" %d", ans[i]);
		}
		puts("");
	}else{
		puts("0");
	}
	return 0;
}
