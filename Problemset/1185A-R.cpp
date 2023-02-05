/*
 * Codeforces 1185A
 * Ropewalkers
 */

#include <cstdio>
#include <iostream>
using namespace std;
int a,b,c,d;
void swap(int& x, int& y){
	x^=y;y^=x;x^=y;
}
void sort(){
	if (a>b) swap(a, b);
	if (a>c) swap(a, c);
	if (b>c) swap(b, c);
}
int main(){
	cin>>a>>b>>c>>d;
	sort();
	int ans = (d>b-a?d-b+a:0) + (d>c-b?d-c+b:0);
	cout<<ans<<endl;
	return 0;
}
