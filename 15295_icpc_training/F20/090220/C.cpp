#include <cstdio>
using namespace std;
typedef long long ll;
int n;
int main(){
	scanf("%d", &n);
	int l=1, r=n;
	ll tar = (ll)n*(n-1)/2ll;
	tar = tar/2;
	while(l<r){
		int mid = (l+r)/2;
		ll cur = (ll)mid*(mid-1)/2ll;
		if (cur>tar) r=mid;
		else l=mid+1;
	}
	printf("%d\n", n-l+1);
	return 0;
}
