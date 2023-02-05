/*
 * Codeforces 1205B
 * Shortest Cycle
 */

#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <cstring>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int mini(int x, int y){return x<y?x:y;}
int n;
vector<ll> dat{};
vector<int> bucket[64];
bool add_buck(ll x, int id){
	int i=0;
	while(x!=0){
		if (x&1){
			bucket[i].push_back(id);
			if (bucket[i].size()>=3) return true;
		}
		i++;x>>=1;
	}
	return false;
}

int un[100100];
int fnd(int x){return (un[x]==x?x:un[x]=fnd(un[x]));}
bool merge(int x, int y){
	if (fnd(x)==fnd(y)) return true;
	un[fnd(x)]=fnd(y);
	return false;
}

bool vis[100100];
vector<int> *v[100100];
queue<pii> q{};
void add_edge(int x, int y){
	if (v[x]==NULL) v[x]=new vector<int>{};
	if (v[y]==NULL) v[y]=new vector<int>{};
	v[x]->push_back(y);
	v[y]->push_back(x);
}
int bfs(int st, int tar){
	memset(vis,0,sizeof(vis));
	while(!q.empty()) q.pop();
	q.push(make_pair(st, 1));
	vis[st]=1;
	while(!q.empty()){
		auto [cur, dep] = q.front();
		if (cur==tar) return dep;
		q.pop();
		for(int i=0;i<v[cur]->size();i++){
			int nxt=(*v[cur])[i];
			if (vis[nxt]) continue;
			vis[nxt]=1;
			q.push(make_pair(nxt, dep+1));
		}
	}
	return -1;
}

int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		ll x;cin>>x;
		dat.push_back(x);
		if (add_buck(x, i)){
			puts("3");
			return 0;
		}
	}
	for(int i=0;i<n;i++) un[i]=i;
	int mn=n+1;
	for(int i=0;i<64;i++){
		if (bucket[i].size()==2){
			bool t=merge(bucket[i][0], bucket[i][1]);
			if (t){
				int dep=bfs(bucket[i][0], bucket[i][1]);
				if (dep>2){
					mn=mini(dep, mn);
					add_edge(bucket[i][0], bucket[i][1]);
				}
			}else{
				add_edge(bucket[i][0], bucket[i][1]);
			}
		}
	}
	if (mn==n+1) puts("-1");
	else cout<<mn<<endl;
	return 0;
}
