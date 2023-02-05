/*
 * Codeforces 1175C
 * Minimal Segment Cover
 */

#include <cstdio>
#include <algorithm>
using namespace std;
int maxi(int x, int y){return y<x?x:y;}
int mini(int x, int y){return x<y?x:y;}
int n,q;
struct seg{
	int l, r;
	seg(){}
	seg(int _l, int _r): l(_l), r(_r){}
	bool operator< (seg y){
		if (l!=y.l) return l<y.l;
		else return r<y.r;
	}
	bool operator== (seg y){
		return l==y.l && r==y.r;
	}
}dat[200100];
int par[200100][20];
int bsearchl(int x, int st){
	int l=st, r=n-1;
	while(l<r){
		int mid = (l+r+1)>>1;
		if (dat[mid].l<=x) l=mid;
		else r = mid-1;
	}
	return l;
}
int main(){
	scanf("%d%d", &n, &q);
	for(int i=0;i<n;i++) scanf("%d%d", &dat[i].l, &dat[i].r);
	sort(dat, dat+n);
	int lst=-1;
	for(int i=0;i<n;i++){
		lst = maxi(lst, dat[i].r);
		dat[i].r = lst;
		par[i][0]=bsearchl(lst, i);
	}
	bool F = 1;
	int m;
	for(m=1;m<20 && F;m++){
		F=0;
		for(int i=0;i<n;i++){
			par[i][m]=par[par[i][m-1]][m-1];
			if (par[i][m]!=par[i][m-1]) F=1;
		}
	}m--;
	for(int t=0;t<q;t++){
		int x,y;scanf("%d%d", &x, &y);
		if (x<dat[0].l){
			puts("-1");
			continue;
		}
		int pos = bsearchl(x, 0);
		if (dat[pos].r>=y){
			puts("1");
			continue;
		}
		int ans = 1, cur = 1, j = 0;
		while(j<m && dat[par[pos][j]].r<y){
			cur<<=1;j++;
		}
		if (j==m){
			puts("-1");
			continue;
		}
		if (j==0){
			puts("2");
			continue;
		}
		cur>>=1;j--;
		ans+=cur;
		pos = par[pos][j];
		while(j>=0){
			while(j>=0 && dat[par[pos][j]].r>=y){
				cur>>=1;j--;
			}
			if (j==-1){
				ans+=1;
				break;
			}
			ans+=cur;
			pos = par[pos][j];
		}
		printf("%d\n", ans);
	}
	return 0;
}
