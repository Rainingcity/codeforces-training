/*
 * Codeforces 1167E
 * Range Deleting
 */

#include <cstdio>
#include <cstring>
using namespace std;
int n, m;
int l[1000100];
int r[1000100];
int nxt[1000100];
int main(){
	scanf("%d %d", &n, &m);
	memset(l, -1, sizeof(l));
	for(int i=0;i<n;i++){
		int x;scanf("%d", &x);x--;
		if (l[x]==-1) l[x]=i;
		r[x]=i;
	}
//	for(int i=0;i<m;i++) if (l[i]!=-1) printf("%d: %d %d\n", i, l[i], r[i]);
	int tail = m-1;
	int lst = m;
	for(;tail>=0;tail--){
		nxt[tail]=lst;
		if (l[tail]!=-1) lst=tail;
	}
	tail = m-1;
	lst = n;
	for(;tail>=1 && (l[tail]==-1 || r[tail]<lst);tail--) if (l[tail]!=-1) lst=l[tail];
	long long ans = m-tail;
//	printf("%d %d %d\n", 0, tail, ans);
	int head = 1;
	lst = -1;
	while(head<m && (l[head-1]==-1 || lst==-1 || l[head-1]>r[lst])){
		if (tail<head) tail=head;
		if (l[head-1]==-1){
			ans += m-tail;
			head++;
			continue;
		}
		while(tail<m-1 && (nxt[tail]!=m && r[head-1]>l[nxt[tail]])) tail=nxt[tail];
		ans += m-tail;
//		printf("%d %d %d\n", head, tail, ans);
		lst = head-1;
		head++;
	}
	printf("%I64d\n", ans);
	return 0;
}
