#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <utility>
#include <cmath>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

int maxi(int x, int y){return x<y?y:x;}
int mini(int x, int y){return x<y?x:y;}

int cnt1[2020];
int cnt2[2020];

int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		int x,y;cin>>x>>y;
		x--;y--;
		cnt1[x+y]++;
		cnt2[x-y+1000]++;
	}
	int sum = 0;
	for(int i=0;i<2000;i++){
		sum += cnt1[i] * (cnt1[i] - 1) / 2;
		sum += cnt2[i] * (cnt2[i] - 1) / 2;
	}
	cout<<sum<<endl;
	return 0;
}
