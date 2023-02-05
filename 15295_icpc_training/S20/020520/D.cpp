#include <iostream>
#include <cstring>
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;
int n;ll X;
ll fp(ll x, ll y){
	if (y==0) return 1;
	if (y==1) return x;
	ll k=fp(x, y>>1);
	k=(k*k)%MOD;
	if (y&1) return (x*k)%MOD;
	else return k;
}
int c2,c3,c5,c7;
ll f[55][35][20][15][13];
ll dfs(int n, int x, int y, int z, int w){
	if (x<0 || y<0 || z<0 || w<0) return 0;
	if (n==0){
		if (x==0 && y==0 && z==0 && w==0){
			return (f[0][0][0][0][0]=1);
		}else{
			return (f[0][0][0][0][0]=0);
		}
	}
	if (f[n][x][y][z][w]!=-1) return f[n][x][y][z][w];
	f[n][x][y][z][w]=(dfs(n-1, x, y, z, w)+dfs(n-1, x-1, y, z, w)
					+dfs(n-1, x, y-1, z, w)+dfs(n-1, x-2, y, z, w)
					+dfs(n-1, x, y, z-1, w)+dfs(n-1, x-1, y-1, z, w)
					+dfs(n-1, x, y, z, w-1)+dfs(n-1, x-3, y, z, w)
					+dfs(n-1, x, y-2, z, w))%MOD;
	return f[n][x][y][z][w];
}
int main(){
	cin>>n>>X;
	if (X==0){
		cout<<(fp(10, n)-fp(9, n)+MOD)%MOD<<endl;
		return 0;
	}
	while(X%2==0){
		c2++;
		X/=2;
	}
	while(X%3==0){
		c3++;
		X/=3;
	}
	while(X%5==0){
		c5++;
		X/=5;
	}
	while(X%7==0){
		c7++;
		X/=7;
	}
	if (X!=1){
		cout<<0<<endl;
		return 0;
	}
	memset(f, -1, sizeof(f));
	cout<<dfs(n, c2, c3, c5, c7)<<endl;
	return 0;
}
