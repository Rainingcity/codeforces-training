#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
typedef pair<int,int> pii;

vector<int> uf{};
int F(int x){return (uf[x]==x?x:(uf[x]=F(uf[x])));}
void U(int x, int y){
	if (uf[x]==uf[y]) return;
	uf[F(uf[x])]=F(uf[y]);
}

struct mine{
	int x,y,life,id;
	mine()=default;
	mine(int _x, int _y, int _life, int _id):x(_x),y(_y),life(_life),id(_id){}
};

bool cmpx(mine x, mine y){
	return x.x!=y.x?x.x<y.x:x.y<y.y;
}

bool cmpy(mine x, mine y){
	return x.y!=y.y?x.y<y.y:x.x<y.x;
}

int n,k;
vector<mine> v;
vector<int> ex_F;
vector<pii> ex;

void work(){
	cin>>n>>k;
	uf.resize(n);
	v.clear();
	ex.clear();
	ex_F.clear();
	ex_F.resize(n,-1);
	for(int i=0;i<n;i++) uf[i]=i;
	for(int i=0;i<n;i++){
		int x,y,life;cin>>x>>y>>life;
		v.push_back(mine(x,y,life,i));
	}
	sort(v.begin(),v.end(),cmpx);
	for(int i=1;i<n;i++){
		if (v[i].x!=v[i-1].x) continue;
		if (v[i].y-v[i-1].y<=k) U(v[i].id,v[i-1].id);
	}
	sort(v.begin(),v.end(),cmpy);
	for(int i=1;i<n;i++){
		if (v[i].y!=v[i-1].y) continue;
		if (v[i].x-v[i-1].x<=k) U(v[i].id,v[i-1].id);
	}
	for(int i=0;i<n;i++){
		if (ex_F[F(v[i].id)]==-1) ex_F[F(v[i].id)]=v[i].life;
		else if (ex_F[F(v[i].id)]>v[i].life) ex_F[F(v[i].id)]=v[i].life;
	}
	for(int i=0;i<n;i++){
		if (F(v[i].id)!=v[i].id) continue;
		ex.push_back(make_pair(ex_F[v[i].id],v[i].id));
	}
	sort(ex.begin(),ex.end());
	int m=ex.size();
	int t=0;
	for(int i=0,j=m-1;i<j;j--,t++){
		while(i<j && ex[i].first<=t) i++;
		if (i==j) break;
	}
	cout<<t<<endl;
	return;
}

int main(){
	int T;cin>>T;
	while(T--){
		work();
	}
	return 0;
}
