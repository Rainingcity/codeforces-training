#include <iostream>
#include <queue>
using namespace std;
typedef long double ld;
int r,s,p;
ld dp[110][110][110];
struct triple{
	int x,y,z;
	triple(){}
	triple(int _x,int _y,int _z){
		x=_x;y=_y;z=_z;
	}
};
ld calc_self(int x,	int y, int z){
	return (ld)(x*(x-1)+y*(y-1)+z*(z-1))/((x+y+z)*(x+y+z-1));
}
bool vis[110][110][110];
queue<triple> q{};
int main(){
	cin>>r>>s>>p;
	dp[r][s][p]=1.0;
	q.push(triple(r,s,p));
	while(!q.empty()){
		triple t=q.front();q.pop();
		auto [x,y,z] = t;
		if (vis[x][y][z]) continue;
		vis[x][y][z] = true;
//		cout<<x<<" "<<y<<" "<<z<<" "<<dp[x][y][z]<<endl;
		ld tt=calc_self(x,y,z);
		if (tt==1) continue;
		ld kx=(ld)2.000*x*z/(x+y+z)/(x+y+z-1)/(1-tt);
		if (kx>0){
			dp[x-1][y][z]+=kx*dp[x][y][z];
			q.push(triple(x-1,y,z));
		}
		ld ky=(ld)2.000*y*x/(x+y+z)/(x+y+z-1)/(1-tt);
		if (ky>0){
			dp[x][y-1][z]+=ky*dp[x][y][z];
			q.push(triple(x,y-1,z));
		}
		ld kz=(ld)2.000*z*y/(x+y+z)/(x+y+z-1)/(1-tt);
		if (kz>0){
			dp[x][y][z-1]+=kz*dp[x][y][z];
			q.push(triple(x,y,z-1));
		}
	}
	cout.precision(15);
	ld ans1=0;
	for(int i=1;i<=r;i++) ans1+=dp[i][0][0];
	ld ans2=0;
	for(int i=1;i<=s;i++) ans2+=dp[0][i][0];
	ld ans3=0;
	for(int i=1;i<=p;i++) ans3+=dp[0][0][i];
	cout<<ans1<<" "<<ans2<<" "<<ans3<<endl;
	return 0;
}
