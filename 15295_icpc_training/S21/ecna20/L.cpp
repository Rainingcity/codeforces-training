#include <queue>
#include <cstring>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <vector>
using namespace std;

vector<vector<int>> v;

#define MAXV 400

typedef int itype;

// This implementation assumes there are not edges going in both directions
itype cap[MAXV][MAXV]; // capacity (input) this array is changed
itype cost[MAXV][MAXV]; // edge cost (input) this array is changed
itype pi[MAXV]; // node potential (intermediate)
itype d[MAXV]; // distance (intermediate)
int p[MAXV]; // path parent (intermediate)

#define INF 1e9
#define EPS 1e-9

/* Returns the min cost for the requested flow or "-1" if the flow can't be
 * made. */
itype mcf(int src, int snk, int n, itype flow) {
	memset(pi, 0, sizeof(pi));
	// Main loop.  Keep adding flow until we get to the desired flow or there are
	// no more augmenting paths.
	itype cst = 0;
	for(itype f = 0; f < flow; ) {
		for(int i = 0; i < n; i++) d[i] = INF;
		memset(p, -1, sizeof(int) * n);
		d[src] = 0; p[src] = -2;
		priority_queue<pair<itype, int> > q;
		q.push(make_pair(0.0, src));
		while(!q.empty()) {
			pair<itype, int> pr = q.top(); q.pop();
			int best = pr.second;
			if(pr.first + d[best] != 0) continue;
			for(int j = 0; j < v[best].size(); j++) {
				int i = v[best][j];
				if(cap[best][i] &&
					 d[best] + cost[best][i] + pi[best] - pi[i] + EPS < d[i]) {
					d[i] = d[best] + cost[best][i] + pi[best] - pi[i];
					p[i] = best;
					q.push(make_pair(-d[i], i));
				}
			}
		}
		if(p[snk] == -1) return INF; // requested flow is impossible
		for(int i = 0; i < n; i++) if(p[i] != -1) pi[i] += d[i];

		itype aug_f = flow - f;
		for(int v = snk; v != src; v = p[v]) {
			aug_f = min(aug_f, cap[p[v]][v]);
		}

		for(int v = snk; v != src; v = p[v]) {
			int u = p[v];
			cap[u][v] -= aug_f;
			cap[v][u] += aug_f;
			cst += aug_f * cost[u][v];
		}
		f += aug_f;
	}
	return cst;
}

int N;
vector<vector<int>> dat;

void reset_graph(int src, int snk){
	for(int i=2;i<N+2;i++){
		cap[src][i]=1;
		cap[i][src]=0;
	}
	for(int i=2;i<N+2;i++){
		for(int j=N+2;j<2*N+2;j++){
			cap[i][j]=1;
			cap[j][i]=0;
		}
	}
	for(int i=N+2;i<2*N+2;i++){
		cap[i][i+N]=1;
		cap[i+N][i]=0;
	}
	for(int i=2*N+2;i<3*N+2;i++){
		for(int j=3*N+2;j<4*N+2;j++){
			cap[i][j]=1;
			cap[j][i]=0;
		}
	}
	for(int i=3*N+2;i<4*N+2;i++){
		cap[i][snk]=1;
		cap[snk][i]=0;
	}
}

int main(){
	cin>>N;
	dat.resize(2*N);
	for(int i=0;i<2*N;i++){
		dat[i].resize(2*N);
		for(int j=0;j<2*N;j++) cin>>dat[i][j];
	}
	int src=0, snk=1, n=4*N+2, flow=N;
	v.resize(n);
	for(int i=2;i<N+2;i++){
		v[src].push_back(i);
		v[i].push_back(src);
		cap[src][i]=1;
		cost[src][i]=1;
		cost[i][src]=-1;
	}
	for(int i=2;i<N+2;i++){
		for(int j=N+2;j<2*N+2;j++){
			v[i].push_back(j);
			v[j].push_back(i);
			cap[i][j]=1;
			cost[i][j]=dat[i-2][2*(j-N-2)+1]+1;
			cost[j][i]=-cost[i][j];
		}
	}
	for(int i=N+2;i<2*N+2;i++){
		v[i].push_back(i+N);
		v[i+N].push_back(i);
		cap[i][i+N]=1;
		cost[i][i+N]=1;
		cost[i+N][i]=-1;
	}
	for(int i=2*N+2;i<3*N+2;i++){
		for(int j=3*N+2;j<4*N+2;j++){
			v[i].push_back(j);
			v[j].push_back(i);
			cap[i][j]=1;
			cost[i][j]=dat[j-2*N-2][2*(i-2*N-2)+1]+1;
			cost[j][i]=-cost[i][j];
		}
	}
	for(int i=3*N+2;i<4*N+2;i++){
		v[i].push_back(snk);
		v[snk].push_back(i);
		cap[i][snk]=1;
		cost[i][snk]=1;
		cost[snk][i]=-1;
	}
	int ans = mcf(src, snk, n, flow);
	int ans_gate = -1;
	vector<int> ans_rec(2*N, 0);
	for(int i=2;i<N+2;i++){
		for(int j=N+2;j<2*N+2;j++){
			if (cap[i][j]) continue;
			ans_rec[i-2]=j-N-2;
			break;
		}
	}
	for(int i=2*N+2;i<3*N+2;i++){
		for(int j=3*N+2;j<4*N+2;j++){
			if (cap[i][j]) continue;
			ans_rec[i-N-2]=j-3*N-2;
			break;
		}
	}
	for(int t=0;t<N;t++){
		reset_graph(src, snk);
		for(int i=2;i<N+2;i++){
			cost[i][N+2+t]=dat[i-2][2*t]+1;
			cost[N+2+t][i]=-cost[i][N+2+t];
		}
		for(int j=3*N+2;j<4*N+2;j++){
			cost[2*N+2+t][j]=dat[j-2*N-2][2*t]+1;
			cost[j][2*N+2+t]=-cost[2*N+2+t][j];
		}
		int cur = mcf(src, snk, n, flow);
		// cout<<cur<<endl;
		if (cur<ans){
			ans=cur;
			ans_gate=t;
			for(int i=2;i<N+2;i++){
				for(int j=N+2;j<2*N+2;j++){
					if (cap[i][j]) continue;
					ans_rec[i-2]=j-N-2;
					break;
				}
			}
			for(int i=2*N+2;i<3*N+2;i++){
				for(int j=3*N+2;j<4*N+2;j++){
					if (cap[i][j]) continue;
					ans_rec[i-N-2]=j-3*N-2;
					break;
				}
			}
		}
	}
	cout<<ans-5*N<<endl;
	for(int i=0;i<N;i++){
		cout<<i+1<<" "<<ans_rec[i]+1<<(ans_rec[i]>ans_gate?"B ":"A ")<<ans_rec[ans_rec[i]+N]+1<<endl;
	}
}
