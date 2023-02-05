#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

vector<vector<int>> v;
vector<int> cnt;
vector<int> about;
vector<int> ready;
vector<int> par;
queue<int> q;

void work(){
	int n,k;scanf("%d%d", &n, &k);

	v.clear();
	v.resize(n);
	cnt.clear();
	cnt.resize(n);
	about.clear();
	about.resize(n);
	ready.clear();
	ready.resize(n);
	par.clear();
	par.resize(n);
	while(!q.empty()) q.pop();

	for(int i=1; i<n; i++){
		int x, y;scanf("%d%d", &x, &y);
		x--;y--;
		v[x].push_back(y);
		v[y].push_back(x);
		cnt[x]++;cnt[y]++;
	}

	for(int i=0; i<n; i++){
		if (cnt[i]==1) {
			q.push(i);
			ready[v[i][0]]++;
		}
	}

	int ans=0;
	while(!q.empty()){
		int x = q.front();q.pop();
		int y = par[x];
		if (about[y]>0){
			about[y]--;
			cnt[y]--;
			cnt[x]--;
		}else if (cnt[y])
	}

}

int main(){
	int T;scanf("%d", &T);
	while(T--){
		work();
	}
}
