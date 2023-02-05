#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int n,d;
int main(){
	cin>>n>>d;
	for(int i=0;i<n;i++){
		int x, a, g, r;
		cin>>x>>a>>g>>r;
		if (x>=d) continue;
		if (x<a){
			puts("NO");
			return 0;
		}
		x=(x-a)%(g+r);
		if (g<x){
			puts("NO");
			return 0;
		}
	}
	puts("YES");
	return 0;
}
