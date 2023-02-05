#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;
int n,m1,m2;
struct edge{
	int x;
	int y;
	int w;
	int id;
	edge(){}
	edge(int _x, int _y, int _w, int _id):x(_x),y(_y),w(_w),id(_id){}
};
typedef pair<int, int> pii;
vector<edge> v[100100];
vector<edge> dat;
int dist[100100];
priority_queue<pii, vector<pii>, greater<pii>> pq;
void dijkstra(int st){
	dist[st]=0;
	pq.push(make_pair(0,st));
	while(!pq.empty()){
		auto [d,e] = pq.front();
		pq.pop();
	}
}
int main(){
	cin>>n>>m1>>m2;
	for(int i=0;i<m1;i++){
		int x,y,w;cin>>x>>y>>w;x--;y--;
		dat.push_back(edge(x,y,w,i));
		v[x].push_back(edge(x,y,w,i));
		v[y].push_back(edge(y,x,w,i));
	}
	for(int i=m1;i<m1+m2;i++){
		int s,w;cin>>s>>w;s--;
		dat.push_back(edge(0,s,w,i));
		v[0].push_back(edge(0,s,w,i));
		v[s].push_back(edge(s,0,w,i));
	}
	dijkstra(0);
}
