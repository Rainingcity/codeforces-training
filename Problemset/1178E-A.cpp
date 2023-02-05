/*
 * Codeforces 1178E
 * Archaeology
 */

#include <iostream>
#include <string>
#include <vector>
using namespace std;
string s;
int n;
vector<char> v;
int main(){
	cin>>s;
	n=s.length();
	int k=n;
	int i=0,j=n-1;
	while(k>=4){
		if (s[i]==s[j]){
			v.push_back(s[j]);
		}else if (s[i+1]==s[j]){
			v.push_back(s[j]);
		}else{
			v.push_back(s[j-1]);
		}
		i+=2;j-=2;k-=4;
	}
	for(auto c: v){
		cout<<c;
	}
	if (k>=1)cout<<s[i];
	for(int i=v.size()-1;i>=0;i--) cout<<v[i];
	cout<<endl;
	return 0;
}
