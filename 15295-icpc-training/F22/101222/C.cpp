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

int n;
vector<ll> p,q,a,b;

int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		int x;cin>>x;
		p.push_back(x);
	}
	for(int i=0;i<n;i++){
		int x;cin>>x;
		q.push_back(x);
	}
	for(int i=0;i<n;i++){
		a.push_back(p[i]-q[i]);
		b.push_back(p[i]+q[i]);
	}
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	sort(p.begin(), p.end());
	sort(q.begin(), q.end());
	ll sum = 0;
	for(int i=1;i<n;i++){
		sum += (p[i]-p[i-1])*i*(n-i);
		sum += (q[i]-q[i-1])*i*(n-i);
	}
	ll dist = 0;
	for(int i=1;i<n;i++){
		dist += (a[i]-a[i-1])*i*(n-i);
		dist += (b[i]-b[i-1])*i*(n-i);
	}
	cout<<sum * 2 - dist<<endl;
	return 0;
}
