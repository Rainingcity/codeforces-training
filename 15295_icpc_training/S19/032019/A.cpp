#include<cstdio>
#include<iostream>
#include<string>
using namespace std;
int n;
int main(){
	cin>>n;
	string pat = "<3";
	for(int i=0;i<n;i++){
		string x = "";
		cin>>x;pat += x+"<3";
	}
	string str;
	cin>>str;
	int k=0;
	for(int i=0;i<str.length() && k<pat.length();i++){
		if (str[i]==pat[k]) k++;
	}
	if (k==pat.length()) puts("yes");
	else puts("no");
	return 0;
}