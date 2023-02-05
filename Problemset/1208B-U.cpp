/*
 * Codeforces 1208B
 * Uniqueness
 */

#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <map>
using namespace std;
char f[130000000];
int n;
vector<int> v;
void modify(int pos, bool x){
	int id=pos/8;
	int loc=pos%8;
	if (x==0) f[id]&=~(1<<loc);
	else f[id]|=(1<<loc);
}
bool get(int pos){
	int id=pos/8;
	int loc=pos%8;
	return (f[id]&(1<<loc))!=0;
}
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		int x;cin>>x;v.push_back(x);
	}
	int ans=n;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++) modify(v[j], false);
		int j;
		for(j=0;j<i;j++){
			if (get(v[j])) break;
			modify(v[j], true);
		}
		if (j!=i) break;
		for(j=n-1;j>=i;j--){
			if (get(v[j])) break;
			modify(v[j], true);
		}
		ans=min(ans, j-i+1);
	}
	cout<<ans<<endl;
	return 0;
}
