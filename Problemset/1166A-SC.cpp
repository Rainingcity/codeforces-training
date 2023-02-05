/*
 * Codeforces 1166A
 * Silent Classroom
 */

#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
using namespace std;
int n;
int cnt[30];
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		string s;cin>>s;
		cnt[s[0]-'a']++;
	}
	int ans=0;
	for(int i=0;i<26;i++){
		int t=cnt[i]>>1;
		ans+=t*(t-1)/2;
		ans+=(cnt[i]-t)*(cnt[i]-t-1)/2;
	}
	printf("%d\n", ans);
	return 0;
}
