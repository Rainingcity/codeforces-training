#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
int n,m;
vector<int> v;
bool check(int k){
	int cur=0;
	for(int i=0;i<n;i++){
		if (v[i]+k>=m){
			if (v[i]+k-m<cur) cur=max(cur, v[i]);
		}else{
			if (cur>v[i]+k) return false;
			else cur=max(cur, v[i]);
		}
	}
	return true;
}
int main(){
	scanf("%d%d", &n, &m);
	v.clear();
	for(int i=0;i<n;i++){
		int x;
		scanf("%d", &x);
		v.push_back(x);
	}
	int l=0, r=m-1;
	while(l<r){
		int mid = (l+r)>>1;
		if (check(mid)) r=mid;
		else l=mid+1;
	}
	printf("%d\n", l);
	return 0;
}
