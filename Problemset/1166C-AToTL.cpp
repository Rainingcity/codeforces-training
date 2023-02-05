/*
 * Codeforces 1166C
 * A Tale of Two Lands
 */

#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int absi(int x){return (x<0?-x:x);}
int n;
int dat[200100];
int main(){
	scanf("%d", &n);
	for(int i=0;i<n;i++){
		scanf("%d", dat+i);
		dat[i]=absi(dat[i]);
	}
	sort(dat,dat+n);
	int l=0,r=1;
	long long ans = 0;
	while(r<n){
		while(l<r && (dat[l]<<1)<dat[r]) l++;
		ans += r-l;
		r++;
	}
	printf("%I64d\n", ans);
	return 0;
}
