#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int n, m;
int solve(){
	cin>>n>>m;
	int mxlast=0, mx=0;
	for(int i=0;i<n;i++){
		int x, y;cin>>x>>y;
		mxlast=max(mxlast, x);
		mx=max(mx, x-y);
	}
	if (mxlast>=m) return 1;
	if (mx==0) return -1;
	return (m-mxlast+mx-1)/mx+1;
}
int main(){
	int T;cin>>T;
	while(T--){
		cout<<solve()<<endl;
	}
}
