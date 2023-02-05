/*
 * Codeforces 1181B
 * Split a Number
 */

#include <cstdio>
using namespace std;
int n;
int a[100100];
int ans[3][100100];
void calc(int pos, int& ansn){
	for(int i=0;pos-i-1>=0;i++) ans[ansn][i]=a[pos-i-1];
	for(int i=0;n-i-1>=pos;i++){
		ans[ansn][i]+=a[n-i-1];
		if (ans[ansn][i]>9){
			ans[ansn][i+1]++;
			ans[ansn][i]-=10;
		}
	}
	for(int i=n-pos;ans[ansn][i]>9;i++){
		ans[ansn][i+1]++;
		ans[ansn][i]-=10;
	}
	ansn++;
}
int order(int i, int j){
	for(int p=100000;p>=0;p--){
		if (ans[i][p]==ans[j][p]) continue;
		if (ans[i][p]>ans[j][p]) return 1;
		else return -1;
	}
	return 0;
}
int getmin(int m){
	int mi=0;
	for(int i=1;i<m;i++){
		if (order(mi, i)==1) mi=i;
	}
	return mi;
}
void print_num(int i){
	int p=100000;
	while(p>0 && ans[i][p]==0) p--;
	for(;p>=0;p--){
		printf("%c", ans[i][p]+'0');
	}
	puts("");
}
int main(){
	scanf("%d", &n);
	int t=0;
	while(t<n){
		char c;
		scanf("%c", &c);
		if (c<'0' || c>'9') continue;
		a[t++]=c-'0';
	}
	int pos=n/2;
	int ansn=0;
	if (a[pos]!=0){
		calc(pos, ansn);
	}
	pos++;
	while(pos<n && a[pos]==0) pos++;
	if (pos<n) calc(pos, ansn);
	pos=n/2-1;
	while(pos>0 && a[pos]==0) pos--;
	if (pos>0) calc(pos, ansn);
	print_num(getmin(ansn));
	return 0;
}
