/*
 * Codeforces 1205A
 * Almost Equal
 */

#include <cstdio>
#include <iostream>
using namespace std;
int n;
int main(){
	cin>>n;
	if (n&1){
		puts("YES");
		cout<<1;
		for(int i=1;i<n;i++){
			cout<<" ";
			if (i&1) cout<<2*i+2;
			else cout<<2*i+1;
		}
		for(int i=0;i<n;i++){
			cout<<" ";
			if (i&1) cout<<2*i+1;
			else cout<<2*i+2;
		}puts("");
	}else{
		puts("NO");
	}
	return 0;
}
