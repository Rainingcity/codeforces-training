#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;
int n;
vector<string> v;
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		string s;cin>>s;
		v.push_back(s);
	}
	sort(v.begin(),v.end());
	ll ans=0;
	for(int i=1;i<v.size();i++){
		string s=v[i-1],t=v[i];
		int j=0;
		for(;j<s.length() && j<t.length();j++){
			if (s[j]!=t[j]) break;
		}
		ans+=j*j;
	}
	cout<<ans<<endl;
	return 0;
}
