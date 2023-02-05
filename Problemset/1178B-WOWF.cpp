/*
 * Codeforces 1178B
 * WOW Factor
 */

#include <iostream>
#include <string>
#include <cstdio>
using namespace std;
string s;
int n;
int main(){
	cin>>s;
	n=s.length();
	if (n<5){
		puts("0");
		return 0;
	}
	int l=(s[0]=='v' && s[1]=='v'),r=0;
	long long ans=0;
	for(int i=3;i<n-1;i++){
		if (s[i]=='v' && s[i+1]=='v') r++;
	}
	for(int i=2;i<n-2;i++){
		if (s[i]=='o'){
			ans+=((long long)l)*r;
		}
		if (s[i-1]=='v' && s[i]=='v') l++;
		if (s[i+1]=='v' && s[i+2]=='v') r--;
	}
	cout<<ans<<endl;
	return 0;
}
