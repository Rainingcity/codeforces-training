/*
 * Codeforces 1167D
 * Bicolored RBS
 */

#include<cstdio>
#include<iostream>
#include<string>
using namespace std;
int n;
string s;
bool c[200100];
bool ans[200100];
int main(){
	cin>>n>>s;
	int mx=0,cur=0;
	for(int i=0;i<n;i++){
		if (s[i]=='(') cur++;
		else cur--;
		if (cur>mx) mx=cur;
	}
	int rmx = mx >> 1;
	cur = 0;
	for(int i=0;i<n;i++){
		if (s[i]=='('){
			if (cur<rmx){
				cout<<'1';
				cur++;
			}else cout<<'0';
		}else{
			if (cur>0){
				cout<<'1';
				cur--;
			}else cout<<'0';
		}
	}
	cout<<endl;
	return 0;
}
