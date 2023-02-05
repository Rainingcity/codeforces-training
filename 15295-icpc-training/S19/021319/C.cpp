#include<cstdio>
#include<vector>
#include<cstring>
using namespace std;
struct tupl{
	int x,y,z;
	tupl(){x=y=z=0;}
	tupl(int _x, int _y, int _z){
		x=_x;y=_y;z=_z;
		if (x>y){
			x=x^y;y=x^y;x=x^y;
		}
		if (x>z){
			x=x^z;z=x^z;x=x^z;
		}
		if (y>z){
			y=y^z;z=y^z;y=y^z;
		}
	}
};
vector<tupl> v;
vector<pair<int,int> > vp;
int n,m;
int a[500];
bool vt[500][500];
int ans;
int main(){
	while(scanf("%d%d", &n, &m)!=EOF){
		ans=0;
		memset(a,0,sizeof(a));
		memset(vt,false,sizeof(vt));
		v.clear();vp.clear();
		for(int i=0;i<n;i++) scanf("%d", a+i);
		for(int i=0;i<m;i++){
			int x,y;scanf("%d%d", &x, &y);x--;y--;
			vt[x][y]=vt[y][x]=true;vp.push_back(make_pair(x,y));
			if (a[x]+a[y]>ans) ans=a[x]+a[y];
		}
		for(int c=0;c<vp.size();c++){
			int i=vp[c].first,j=vp[c].second;
			if (i>j){
				i=i^j;j=i^j;i=i^j;
			}
			for(int k=j+1;k<n;k++){
				if (vt[i][j] && vt[j][k] && vt[i][k]){
					v.push_back(tupl(i,j,k));
				}
			}
		}
		for(int c=0;c<v.size();c++){
			int i=v[c].x,j=v[c].y,k=v[c].z;
			int curans=a[i]+a[j]+a[k];
			if (curans>ans) ans=curans;
			for(int l=k+1;l<n;l++){
				if (vt[i][l] && vt[j][l] && vt[k][l]){
					if (curans+a[l]>ans) ans=curans+a[l];
				}
			}
		}
		printf("%d\n", ans);
	}
}
