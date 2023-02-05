/*
 * Codeforces 1204B
 * Mislove Has Lost an Array
 */

#include <cstdio>
#include <iostream>
using namespace std;
int n,l,r;
int main(){
	cin>>n>>l>>r;
	int ansl=(1<<l)-1+(n-l);
	int ansr=(1<<r)-1+((1<<r)>>1)*(n-r);
	cout<<ansl<<" "<<ansr<<endl;
	return 0;
}
