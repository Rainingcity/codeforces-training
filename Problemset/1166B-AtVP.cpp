/*
 * Codeforces 1166B
 * All the Vowels Please
 */

#include <cstdio>
#include <iostream>
#include <string>
using namespace std;
int n;
char mp[2010][2010];
string v = "aeiou";
string construct(int r, int c){
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			mp[i][j]=v[(i+j)%5];
		}
	}
	string s (mp[0]);
	for(int i=1;i<r;i++) s += string(mp[i]);
	return s;
}
int main(){
	cin>>n;
	for(int i=5;i*i<=n;i++){
		if (n%i==0){
			string s = construct(i, n/i);
			cout<<s<<endl;
			return 0;
		}
	}
	cout<<-1<<endl;
	return 0;
}
