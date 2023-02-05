/*
 * Codeforces 1208A
 * XORinacci
 */

#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;
void solve(){
	int a,b,n;
	cin>>a>>b>>n;
	if (n%3==0){
		cout<<a<<endl;
	}else if (n%3==1){
		cout<<b<<endl;
	}else{
		cout<<(a^b)<<endl;
	}return;
}

int main(){
	int T;cin>>T;
	while(T--){
		solve();
	}
}
