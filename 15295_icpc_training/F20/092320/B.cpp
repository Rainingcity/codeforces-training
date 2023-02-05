#include <iostream>
#include <vector>
#include <string>
using namespace std;
typedef long long ll;
const ll MOD=1e9+7;
string s;
ll fib[100100];
int main(){
	cin>>s;
	int n=s.length();
	fib[0]=1;
	fib[1]=1;
	fib[2]=2;
	for(int i=3;i<=n;i++) fib[i]=(fib[i-1]+fib[i-2])%MOD;
	ll ans=1;
	int cur=0;
	for(int i=0;i<n;i++){
		if (s[i]=='m' || s[i]=='w'){
			cout<<0<<endl;
			return 0;
		}
		if (i && s[i]!=s[i-1]){
			ans=(ans*fib[i-cur])%MOD;
			cur=i;
		}else if (s[i]!='n' && s[i]!='u'){
			cur++;
		}
	}
	ans=(ans*fib[n-cur])%MOD;
	cout<<ans<<endl;
	return 0;
}
