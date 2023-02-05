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

int n,m;
vector<int> vis;
queue<int> q;

int main(){
	cin>>n>>m;
	if (n>=m){
		cout<<n-m<<endl;
		return 0;
	}
	vis.resize(m+1, 0);
	q.push(n);
	vis[n]=0;
	while(!q.empty()){
		int curr = q.front();
		q.pop();
		if (curr>0 && !vis[curr-1]){
			vis[curr-1]=vis[curr]+1;
			q.push(curr-1);
		}
		if (2*curr>=m){
			if (!vis[m]) vis[m]=vis[curr]+1+(2*curr-m);
			else vis[m]=mini(vis[m], vis[curr]+1+(2*curr-m));
		}else if (!vis[2*curr]){
			vis[2*curr]=vis[curr]+1;
			q.push(2*curr);
		}
	}
	cout<<vis[m]<<endl;
	return 0;
}
