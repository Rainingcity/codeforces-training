#include <iostream>
#include <string>
using namespace std;
typedef long long ll;
string dat;
ll nb,ns,nc,pb,ps,pc,r;
ll b,s,c;
bool calc(ll x, ll y, ll z){
	return ((x<=nb?0:(x-nb)*pb)+(y<=ns?0:(y-ns)*ps)+(z<=nc?0:(z-nc)*pc))<=r;
}
int main(){
	cin>>dat;
	cin>>nb>>ns>>nc;
	cin>>pb>>ps>>pc;
	cin>>r;
	for(auto x: dat){
		if (x=='B') b++;
		else if (x=='S') s++;
		else if (x=='C') c++;
	}
	ll left=0, right=r+nb+ns+nc;
	while(left<right){
		ll mid=(left+right+1)>>1;
		if (calc(mid*b, mid*s, mid*c)) left=mid;
		else right=mid-1;
	}
	cout<<left<<endl;
}
