/*
 * Codeforces 1208C
 * Magic Grid
 */

#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;
int mask[4][4]={{8,9,1,13},{3,12,7,5},{0,2,4,11},{6,10,15,14}};
int main(){
	int n;cin>>n;
	int k=n/4;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if (j) cout<<" ";
			int block=(i/4)*k+(j/4);
			cout<<mask[i%4][j%4]+16*block;
		}cout<<endl;
	}
	return 0;
}
