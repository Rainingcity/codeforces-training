#include <iostream>
#include <vector>
using namespace std;
int n,m;
vector<bool> v;
vector<int> can;
vector<int> cnt;

int F(int x){return (can[x]==x?x:(can[x]=F(can[x])));}
void U(int x, int y){
	if (F(x)==F(y)) return;
	can[F(y)]=F(x);
}

int main(){
	cin>>n;
	can.resize(n);
	cnt.resize(n);
	for(int i=0;i<n;i++) can[i]=i;
	for(int i=0;i<n;i++){
		int x;cin>>x;
		v.push_back(x);
	}
	cin>>m;
	for(int i=0;i<m;i++){
		int x,y;cin>>x>>y;
		U(x-1, y-1);
	}
	for(int i=0;i<n;i++){
		if (!v[i]) continue;
		cnt[F(i)]++;
	}
	for(int i=0;i<n;i++){
		if (cnt[i]&1){
			cout<<"No"<<endl;
			return 0;
		}
	}
	cout<<"Yes"<<endl;
	return 0;
}
