/*
 * Codeforces 1194C
 * From S To T
 */

#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
void solve(){
	string s, t, p;
	cin>>s>>t>>p;
	vector<int> cnt{};cnt.resize(26);
	int n=s.length(), m=t.length();
	for(int i=0;i<p.length();i++){
		cnt[p[i]-'a']++;
	}
	vector<int> cnt2{};cnt2.resize(26);
	int i=0;
	for(int j=0;j<m;j++){
		if (i<n && s[i]==t[j]) i++;
		else{
			cnt2[t[j]-'a']++;
		}
	}
	if (i<n){
		puts("NO");
		return;
	}
	for(int i=0;i<26;i++){
		if (cnt2[i]>cnt[i]){
			puts("NO");
			return;
		}
	}
	puts("YES");
	return;
}
int main(){
	int T;cin>>T;
	while(T--){
		solve();
	}
	return 0;
}
