#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <utility>
#include <cmath>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

int maxi(int x, int y){return x<y?y:x;}
int mini(int x, int y){return x<y?x:y;}

int n,m,k;
vector<int> uf;
vector<int> c;
vector<int> cf;
vector<pair<pii, int>> edges;
vector<vector<int>> v;

int F(int x){return (uf[x]==x?x:(uf[x]=F(uf[x])));}
void U(int x, int y){
	if (F(x)==F(y)) return;
	uf[F(x)]=F(y);
	return;
}

int main(){
	cin>>n>>m>>k;
	uf.resize(n);
	for(int i=0;i<k;i++){
		int x;cin>>x;c.push_back(x);
	}
	for(int i=0;i<n;i++) uf[i]=i;
	for(int i=0;i<m;i++){
		int x,y,w;cin>>x>>y>>w;
		x--;y--;
		edges.push_back(make_pair(make_pair(x, y), w));
		if (w==0) U(x, y);
	}

	for(int i=0,j=0;i<n;i+=c[j],j++){
		cf.push_back(j);
		for(int i2=i+1;i2<i+c[j];i2++){
			cf.push_back(j);
			if (F(i2-1)!=F(i2)){
				cout<<"No"<<endl;
				return 0;
			}
		}
	}

	v.resize(k);
	for(int i=0;i<k;i++){
		v[i].resize(k,-1);
		v[i][i]=0;
	}
	for(int i=0;i<m;i++){
		int x=edges[i].first.first;
		int y=edges[i].first.second;
		int w=edges[i].second;
		x=cf[x],y=cf[y];
		if (x==y) continue;
		if (v[x][y]==-1){
			v[x][y]=v[y][x]=w;
		}else if (v[x][y]>w){
			v[x][y]=v[y][x]=w;
		}
	}
	for(int t=0;t<k;t++){
		for(int i=0;i<k;i++){
			for(int j=0;j<k;j++){
				if (v[i][t]==-1 || v[t][j]==-1) continue;
				if (v[i][j]==-1 || v[i][t]+v[t][j]<v[i][j]){
					v[i][j]=v[j][i]=v[i][t]+v[t][j];
				}
			}
		}
	}
	cout<<"Yes"<<endl;
	for(int i=0;i<k;i++){
		cout<<v[i][0];
		for(int j=1;j<k;j++){
			cout<<" "<<v[i][j];
		}
		cout<<endl;
	}
	return 0;
}
