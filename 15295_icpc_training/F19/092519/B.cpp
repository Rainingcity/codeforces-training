#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>
using namespace std;
vector<string> ans;
int n;
bool check(string s){
	if (s.length()<6) return false;
	bool f1=0,f2=0,f3=0,f4=0;
	for(int i=0;i<s.length();i++){
		if ('0'<=s[i] && s[i]<='9') f3=1;
		if ('a'<=s[i] && s[i]<='z') f2=1;
		if ('A'<=s[i] && s[i]<='Z') f1=1;
		if (s[i]=='.' || s[i]==',' || s[i]==';' || s[i]==':' || s[i]=='?' || s[i]=='!') f4=1;
	}
	return f1 && f2 && f3 && f4;
}
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		string s;cin>>s;
		if (check(s)) ans.push_back(s);
	}
	cout<<ans.size()<<endl;
	for(int i=0;i<ans.size();i++){
		cout<<ans[i]<<endl;
	}
	return 0;
}
