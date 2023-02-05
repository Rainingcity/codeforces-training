#include <iostream>
#include <string>
using namespace std;
typedef long long ll;
const ll MOD=11092019;
ll cnt[26];
string s;
int main(){
	cin>>s;
	int n=s.length();
	for(int i=0;i<n;i++){
		cnt[s[i]-'a']++;
	}
	ll ans=1;
	for(int i=0;i<26;i++){
		if (cnt[i]!=0) ans=(ans*(cnt[i]+1))%MOD;
	}
	cout<<ans<<endl;
	return 0;
}
