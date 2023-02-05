#include <iostream>
#include <utility>
#include <vector>
using namespace std;
typedef pair<int,int> pii;
int maxi(int x, int y){return x<y?y:x;}

int n,k,m,q,b;
int s[6][6];
vector<pii> v;
vector<int> score;

bool dfs(int cur){
	if (cur==q){
		return true;
	}
	if (score[v[cur].first]+3<b){
		score[v[cur].first]+=3;
		bool ret = dfs(cur+1);
		score[v[cur].first]-=3;
		if (ret) return true;
	}
	if (score[v[cur].second]+3<b){
		score[v[cur].second]+=3;
		bool ret = dfs(cur+1);
		score[v[cur].second]-=3;
		if (ret) return true;
	}
	if (score[v[cur].first]+1<b && score[v[cur].second]+1<b){
		score[v[cur].first]++;
		score[v[cur].second]++;
		bool ret = dfs(cur+1);
		score[v[cur].first]--;
		score[v[cur].second]--;
		if (ret) return true;
	}
	return false;
}

int main(){
	cin>>n>>k>>m;
	score.resize(n);
	k--;
	for(int i=0;i<m;i++){
		int x,px,y,py;
		cin>>x>>px>>y>>py;
		x--;y--;
		if (x==k || x==0) x=k-x;
		if (y==k || y==0) y=k-y;

		s[x][y]=px;
		s[y][x]=py;

		score[x]+=px;
		score[y]+=py;
	}
	if (m==0){
		cout<<"YES"<<endl;
		return 0;
	}
	if (m==1 && n>=4){
		cout<<"YES"<<endl;
		return 0;
	}
	if (m==2 && n>=6){
		cout<<"YES"<<endl;
		return 0;
	}
	for(int j=1;j<n;j++){
		if (s[0][j]+s[j][0]<2){
			s[0][j]=3;s[j][0]=0;
			score[0]+=3;
		}
	}
	int mx=0;
	for(int j=1;j<n;j++) mx=maxi(score[j], mx);
	if (mx>=score[0]){
		cout<<"NO"<<endl;
		return 0;
	}
	for(int i=1;i<n;i++){
		for(int j=i+1;j<n;j++){
			if (s[i][j]+s[j][i]<2) v.push_back(make_pair(i,j));
		}
	}
	q=(int)v.size();
	b=score[0];
	bool ret = dfs(0);
	if (ret){
		cout<<"YES"<<endl;
	}else{
		cout<<"NO"<<endl;
	}
}
