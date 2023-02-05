/*
 * Codeforces 1167A
 * Telephone Number
 */

#include<cstdio>
#include<iostream>
using namespace std;
int n;
string s;
int main(){
	int T;cin>>T;
	while(T--){
		cin>>n>>s;
		int k = s.find('8');
		if (k==string::npos) puts("NO");
		else if (n-k<11) puts("NO");
		else puts("YES");
	}
	return 0;
}
