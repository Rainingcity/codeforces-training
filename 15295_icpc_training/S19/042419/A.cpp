#include<cstdio>
#include<string>
#include<iostream>
#include<cstring>
using namespace std;
string x,y;
int cntx[200100][30];
int cnty[200100][30];
bool rec(int lx, int rx, int ly, int ry){
//	printf("%d %d %d %d\n", lx, rx, ly, ry);
	for(int i=0;i<26;i++){
		if (cntx[rx]-cntx[lx-1]!=cnty[ry]-cnty[ly-1]) return false;
	}
	if (x.substr(lx-1,rx-lx+1)==y.substr(ly-1,ry-ly+1)) return true;
	if ((rx-lx+1)&1) return false;
	int midx = (lx+rx)>>1;
	int midy = (ly+ry)>>1;
	bool F=1;
	for(int i=0;i<26 && F;i++){
		if (cntx[rx][i]-cntx[midx][i]!=cnty[ry][i]-cnty[midy][i]) F=0;
		if (cntx[midx][i]-cntx[lx-1][i]!=cnty[midy][i]-cnty[ly-1][i]) F=0;
	}
//	printf("%d\n", F);
	if (F && rec(lx,midx,ly,midy) && rec(midx+1,rx,midy+1,ry)) return true;
	F=1;
	for(int i=0;i<26 && F;i++){
		if (cntx[rx][i]-cntx[midx][i]!=cnty[midy][i]-cnty[ly-1][i]) F=0;
		if (cntx[midx][i]-cntx[lx-1][i]!=cnty[ry][i]-cnty[midy][i]) F=0;
	}
//	printf("%d\n", F);
	return F && rec(lx,midx,midy+1,ry) && rec(midx+1,rx,ly,midy);
}
int main(){
	cin>>x>>y;
	int len = x.length();
	for(int i=0;i<len;i++){
		for(int j=0;j<26;j++) cntx[i+1][j]=cntx[i][j];
		for(int j=0;j<26;j++) cnty[i+1][j]=cnty[i][j];
		cntx[i+1][x[i]-'a']++;
		cnty[i+1][y[i]-'a']++;
	}
/*	for(int i=0;i<=len;i++){
		for(int j=0;j<26;j++) printf("%d ", cntx[i][j]);
		puts("");
	}
	puts("");
	for(int i=0;i<=len;i++){
		for(int j=0;j<26;j++) printf("%d ", cnty[i][j]);
		puts("");
	}
	puts("");
*/	if (rec(1,len,1,len)) puts("YES");
	else puts("NO");
	return 0;
}
