/*
 * Codeforces 1178C
 * Tiles
 */

#include <iostream>
using namespace std;
const int MOD = 998244353;
int pow2(int x){
	if (x==1) return 2;
	if (x==0) return 1;
	return (pow2(x-1)*2) % MOD;
}
int main(){
	int w,h;cin>>w>>h;
	cout<<pow2(w+h)<<endl;
	return 0;
}
