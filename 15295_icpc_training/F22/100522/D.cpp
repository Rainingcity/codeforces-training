#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <utility>
#include <cmath>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

int maxi(int x, int y){return x<y?y:x;}
int mini(int x, int y){return x<y?x:y;}

int n,k;
bool f[1010];
int v[1010];
queue<int> q;
int mi=1000;

int main(){
	scanf("%d%d", &n, &k);
	for(int i=0;i<k;i++){
		int x;scanf("%d", &x);f[x]=true;
	}
	if (f[n]){
		puts("1");
		return 0;
	}
	bool F=false;
	for(int i=0;i<n;i++){
		if (f[i]) F=true;
	}
	if (!F){
		puts("-1");
		return 0;
	}
	F=false;
	for(int i=n+1;i<=1000;i++){
		if (f[i]) F=true;
	}
	if (!F){
		puts("-1");
		return 0;
	}
	for(int i=0;i<=1000;i++){
		if (f[i]){
			mi=n-i;
			break;
		}
	}
	for(int i=n+1;i<=1000;i++){
		if (!f[i]) continue;
		v[i-n]=1;
		q.push(i-n);
	}
	while(!q.empty()){
		if (v[0]){
			printf("%d\n", v[0]);
			return 0;
		}
		int curr=q.front();q.pop();
		if (curr>1000) continue;
		for(int i=maxi(0,n-curr);i<=1000 && curr+i-n<=1000;i++){
			if (!f[i]) continue;
			if (v[curr+i-n]) continue;
			v[curr+i-n]=v[curr]+1;
			q.push(curr+i-n);
		}
	}
	//SHOULD NOT WORK!!!
	puts("-1");
	return 0;
}
