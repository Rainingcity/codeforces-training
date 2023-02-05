#include <iostream>
#include <string>
using namespace std;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
int n,m;
int g[110][110];
int A[110][110];
int B[110][110];
int ax,ay,bx,by;
bool valid(int x, int y){
	return (0<=x && x<n && 0<=y && y<m);
}
int fnd_st_dir(int x, int y){
	for(int i=0;i<4;i++){
		int nx=x+dx[i],ny=y+dy[i];
		if (valid(nx,ny) && g[nx][ny]) return i;
	}
	return -1;
}
void circle(int curx, int cury, int dir, auto& tar){
	if (tar[curx][cury]==1) return;
	tar[curx][cury]=1;
	int nx=curx+dx[dir],ny=cury+dy[dir];
	if (valid(nx,ny) && g[nx][ny]){
		circle(nx,ny,dir,tar);
		return;
	}
	int ndir=(dir+1)%4;
	nx=curx+dx[ndir],ny=cury+dy[ndir];
	if (valid(nx,ny) && g[nx][ny]){
		circle(nx,ny,ndir,tar);
		return;
	}
	ndir=(dir+3)%4;
	nx=curx+dx[ndir],ny=cury+dy[ndir];
	if (valid(nx,ny) && g[nx][ny]) circle(nx,ny,ndir,tar);
	return;
}
void paint(int curx, int cury, auto& tar){
	tar[curx][cury] = 2;
	for(int i=0;i<4;i++){
		int nx=curx+dx[i],ny=cury+dy[i];
		if (valid(nx,ny) && !tar[nx][ny]) paint(nx,ny,tar);
	}
	return;
}
int main(){
	cin>>n>>m;
	for(int i=0;i<n;i++){
		string s;cin>>s;
		for(int j=0;j<m;j++){
			if (s[j]=='X') g[i][j]=1;
			else if (s[j]=='A'){
				g[i][j]=1;
				ax=i;ay=j;
			}else if (s[j]=='B'){
				g[i][j]=1;
				bx=i;by=j;
			}else g[i][j]=0;
		}
	}
	circle(ax,ay,fnd_st_dir(ax,ay),A);
	circle(bx,by,fnd_st_dir(bx,by),B);
	for(int i=0;i<n;i++){
		if (A[i][0]==0) paint(i,0,A);
		if (B[i][0]==0) paint(i,0,B);
		if (A[i][m-1]==0) paint(i,m-1,A);
		if (B[i][m-1]==0) paint(i,m-1,B);
	}
	for(int j=0;j<m;j++){
		if (A[0][j]==0) paint(0,j,A);
		if (B[0][j]==0) paint(0,j,B);
		if (A[n-1][j]==0) paint(n-1,j,A);
		if (B[n-1][j]==0) paint(n-1,j,B);
	}
/*	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++)
			cout<<A[i][j];
		cout<<endl;
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++)
			cout<<B[i][j];
		cout<<endl;
	}*/
	int ansA=0,ansB=0,ansC=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if (g[i][j]==0){
				if (A[i][j]==0 && B[i][j]==0) ansC++;
				else if (A[i][j]==0) ansA++;
				else if (B[i][j]==0) ansB++;
			}
		}
	}
	cout<<ansA<<" "<<ansB<<" "<<ansC<<endl;
	return 0;
}
