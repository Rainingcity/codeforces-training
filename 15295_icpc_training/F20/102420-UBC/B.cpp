#include <cstdio>
#include <vector>
using namespace std;
inline int maxi(int x, int y){return x>y?x:y;}
int n,m;
vector<int> v;
int count(int x){
	int cur=0,grp=0;
	for(int i=0;i<n;i++){
		cur+=v[i];
		if (cur>x){
			grp++;
			cur=v[i];
		}
	}
	return grp+1;
}
int main(){
	scanf("%d%d", &n, &m);
	int sum=0;
	int mx=0;
	for(int i=0;i<n;i++){
		int x;scanf("%d", &x);
		v.push_back(x);
		sum+=x;
		mx=maxi(mx, x);
	}
	int l=mx,r=sum;
	while(l<r){
		int mid=(l+r)>>1;
		if (count(mid)>m) l=mid+1;
		else r=mid;
	}
	printf("%d\n", r);
	return 0;
}
