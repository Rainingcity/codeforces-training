/*
 * Codeforces 1179B
 * Tolik and His Uncle
 */

#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
int n,m;
vector<vector<bool>> v;
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
struct Node{
	int x,y,dir;
	Node(){}
	Node(int _x, int _y, int _dir){
		x=_x;y=_y;dir=_dir;
	}
};
int main(){
	scanf("%d%d", &n, &m);
	v.resize(n+2);
	for(int i=0;i<n+2;i++) v[i].resize(m+2);
	for(int i=0;i<n+2;i++){
		v[i][0]=v[i][m+1]=true;
	}
	for(int j=0;j<m+2;j++){
		v[0][j]=v[n+1][j]=true;
	}
	Node l(1,1,0), r(n, m, 2);
	int count=0;
	while(count<n*m){
		count++;
		printf("%d %d\n", l.x, l.y);
		v[l.x][l.y]=true;
		int tt=0;
		while(tt<4 && v[l.x+dx[l.dir]][l.y+dy[l.dir]]){
			l.dir=(l.dir+1)%4;tt++;
		}
		l.x+=dx[l.dir];l.y+=dy[l.dir];
		Node t = l;
		l = r;
		r = t;
	}
	return 0;
}
