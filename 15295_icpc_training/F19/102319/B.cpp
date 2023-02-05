#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;
const int N = 5000000;
int f[5000100];
vector<int> v;
int ans[5000100];
void preprocess(){
	for(int i=2;i<=N;i++){
		if (f[i]==0) v.push_back(i);
		for(int j=0;j<v.size();j++){
			if (i*v[j]>N) break;
			f[i*v[j]]=v[j];
			if (i%v[j]==0) break;
		}
	}
	for(int i=2;i<=N;i++){
		if (f[i]==0) ans[i]=1;
		else ans[i]=ans[i/f[i]]+1;
	}
	for(int i=2;i<=N;i++){
		ans[i]+=ans[i-1];
	}
	return;
}
int main(){
	preprocess();
	int T;scanf("%d", &T);
	while(T--){
		int x,y;scanf("%d%d", &x, &y);
		printf("%d\n", ans[x]-ans[y]);
	}
	return 0;
}
