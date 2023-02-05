/*
 * Codeforces 1187B
 * Letters Shop
 */

#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int maxi(int x, int y){return x<y?y:x;}
int n, m;
string s;
vector<int> v[30];
int main(){
	cin>>n>>s>>m;
	for(int i=0;i<26;i++) v[i].push_back(0);
	for(int i=0;i<n;i++){
		v[s[i]-'a'].push_back(i+1);
	}
	for(int i=0;i<m;i++){
		string name;
		cin>>name;
		int cnt[30];
		for(int j=0;j<26;j++) cnt[j]=0;
		for(int j=0;j<name.length();j++) cnt[name[j]-'a']++;
		int mx=0;
		for(int j=0;j<26;j++) mx=maxi(v[j][cnt[j]], mx);
		printf("%d\n", mx);
	}
	return 0;
}
