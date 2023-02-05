/*
 * Codeforces 1172A
 * Nauuo and Cards
 */

#include <cstdio>
#include <queue>
using namespace std;
int maxi(int x, int y){return x<y?y:x;}
int n;
bool hands[200100];
int hempty;
bool deck[200100];
queue<int> d;

int check(int st){
	for(int i=st;i<=n;i++){
		if (!hands[i]) return -1;
		hands[i]=0;
		d.push(i);
		int t = d.front();d.pop();
		if (t==0) hempty++;
		else hands[t]=1;
	}
	return (hempty==n?n-st+1:-1);
}

int main(){
	scanf("%d", &n);
	for(int i=0;i<n;i++){
		int x;scanf("%d", &x);
		if (x==0) hempty++;
		else hands[x]=1;
	}
	int pos=1;
	int mx=-n;
	for(int i=0;i<n;i++){
		int x;scanf("%d", &x);
		d.push(x);
		deck[x]=1;
		if (x!=0) mx = maxi(mx, i-x+2);
		if (x==pos){
			pos++;
		}else if (pos!=1) pos=-1;
	}
	if (pos>0){
		int ans = check(pos);
		if (ans==-1) printf("%d\n", n+mx);
		else printf("%d\n", ans);
	}else{
		printf("%d\n", n+mx);
	}
	return 0;
}
