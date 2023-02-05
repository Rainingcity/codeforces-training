/*
 * Codeforces 1168A
 * Increasing by Modulo
 */

#include <cstdio>
using namespace std;
int n, m;
int find_smallest(int cur, int inc, int mi){
	if (cur + inc < m){
		if (mi > cur + inc) return -1;
		else return (mi < cur ? cur : mi);
	}else{
		int t = cur + inc - m;
		if (mi<=t) return mi;
		return (mi < cur ? cur : mi);
	}
}
int dat[300100];
bool is_possible(int inc){
	int mi = 0;
	for(int i=0;i<n;i++){
		mi = find_smallest(dat[i], inc, mi);
		if (mi==-1) return false;
	}
	return true;
}
int main(){
	scanf("%d %d", &n, &m);
	for(int i=0;i<n;i++) scanf("%d", dat+i);
	int l=0, r=m-1;
	while(l<r){
		int mid = (l+r)>>1;
		if (is_possible(mid)) r = mid;
		else l = mid + 1;
	}
	printf("%d\n", l);
	return 0;
}
