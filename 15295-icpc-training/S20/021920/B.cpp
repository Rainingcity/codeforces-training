#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef long long ll;
typedef long double ld;
const ld inf = 1e18;
const ld eps = 1e-18;
ll mini(ll x, ll y){return x<y?x:y;}
ld mini(ld x, ld y){return x<y?x:y;}
ld absi(ld x){return x<0?-x:x;}
ld V;int n,m;
vector<vector<ld>> a;
vector<vector<int>> dat;
vector<vector<ld>> dist;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
bool valid(int x, int y){
	return 0<=x && x<n && 0<=y && y<m;
}
int main(){
	cin>>V>>n>>m;
	a.resize(n);
	dat.resize(n);
	dist.resize(n);
	for(int i=0;i<n;i++){
		dist[i].resize(m, inf);
		a[i].resize(m);
		for(int j=0;j<m;j++){
			int x;cin>>x;dat[i].push_back(x);
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if (dat[i][j]>=dat[0][0]) a[i][j]=ld(1ll<<(dat[i][j]-dat[0][0]))/V;
			else a[i][j]=1.0/V/ld(1ll<<(dat[0][0]-dat[i][j]));
		}
	}
	dist[0][0]=0.0;
	priority_queue<pair<ld, pair<int,int>>> pq{};
	pq.push(make_pair(0.0, make_pair(0,0)));
	while(!pq.empty()){
		auto [val, cur]=pq.top();
		auto [cx, cy]=cur;
		// cout<<val<<" "<<cx<<" "<<cy<<endl;
		val-=a[cx][cy];
		pq.pop();
		if (absi(val+dist[cx][cy])<eps) continue;
		for(int i=0;i<4;i++){
			int nx=cx+dx[i],ny=cy+dy[i];
			if (!valid(nx, ny)) continue;
			if (-val>=dist[nx][ny]) continue;
			dist[nx][ny]=-val;
			pq.push(make_pair(val, make_pair(nx, ny)));
		}
	}
	/*
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cout<<" "<<dist[i][j];
		}cout<<endl;
	}
	*/
	cout.precision(8);
	cout<<dist[n-1][m-1]<<endl;
	return 0;
}
