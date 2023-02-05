/*
 * Codeforces 1168B
 * Good Triple
 */

#include <cstdio>
#include <iostream>
using namespace std;
typedef long long ll;
string s;
int n;
ll ans;

bool check(int x, int y){
	for(int i=x;i<=y;i++){
		for(int j=1;i+j+j<=y;j++){
			if (s[i]==s[i+j] && s[i]==s[i+j+j]) return true;
		}
	}
	return false;
}

int main(){
	cin>>s;
	n = s.length();
	for(int i=0;i<n;i++){
		int j = i;
		for(;j<n && j-i<8;j++){
			if (check(i,j)) ans++;
		}
		ans += (ll)(n-j);
	}
	cout<<ans<<endl;
	return 0;
}
