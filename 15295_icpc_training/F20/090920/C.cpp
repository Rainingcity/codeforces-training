#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
int n,m;
vector<int> a,b;
int main(){
	cin>>n>>m;
	for(int i=0;i<n;i++){
		int x;cin>>x;
		a.push_back(x);
	}
	for(int i=0;i<m;i++){
		int x;cin>>x;
		b.push_back(x);
	}
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	int i=0,j=0;
	ll ans=0, cur=0;
	ll mn=min(a[i], b[j]);
	for(int k=0;k<m;k++) cur+=b[k]-mn;
	ans=cur;
	if (a[i]<b[j]) i++;
	else j++;
	while(i<n && j<m){
		ll nmn=min(a[i], b[j]);
		cur+=i*(nmn-mn);
		cur-=(m-j)*(nmn-mn);
		mn=nmn;
		ans=min(ans, cur);
		if (a[i]<b[j]) i++;
		else j++;
	}
	while(j<m){
		ll nmn=b[j];
		cur+=i*(nmn-mn);
		cur-=(m-j)*(nmn-mn);
		mn=nmn;
		ans=min(ans, cur);
		j++;
	}
	cout<<ans<<endl;
	return 0;
}
