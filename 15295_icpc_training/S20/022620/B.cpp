#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <utility>
using namespace std;
vector<int> f;
int F(int x){
	return (x==f[x]?x:(f[x]=F(f[x])));
}
bool U (int x, int y){
	if (F(x)==F(y)) return false;
	f[f[x]]=f[y];
	return true;
}
int n;
map<int,vector<int>> mp{};
struct ans_rep{
	int x, y, num;
	ans_rep()=default;
	ans_rep(int _x, int _y, int _num){
		x=_x; y=_y; num=_num;
	}
};
vector<ans_rep> ans;
int main(){
	scanf("%d", &n);
	f.resize(n+1);
	for(int i=1;i<=n;i++) f[i]=i;
	for(int i=1;i<=n;i++){
		int m;scanf("%d", &m);
		for(int j=0;j<m;j++){
			int x;scanf("%d", &x);
			if (mp.find(x)==mp.end()){
				mp.emplace(x,vector<int>{i});
			}else mp[x].push_back(i);
		}
	}
	for (auto& [num, v]: mp){
		int prev=-1;
		for(auto& cur: v){
			if (prev!=-1){
				if (U(prev,cur)){
					ans.push_back(ans_rep(prev, cur, num));
				}
			}
			prev=cur;
		}
	}
	if (ans.size()<n-1){
		puts("impossible");
	}else{
		for(int i=0;i<ans.size();i++){
			printf("%d %d %d\n", ans[i].x, ans[i].y, ans[i].num);
		}
	}
	return 0;
}
