/*
 * Codeforces 1182B
 * Plus from Picture
 */

#include <cstdio>
#include <iostream>
#include <utility>
#include <set>
using namespace std;
int n, m;
bool graph[510][510];
bool check3x3(int x, int y){
	if (x==0 || x==n-1) return false;
	if (y==0 || y==m-1) return false;
	return  graph[x-1][y-1]==false && graph[x-1][y]==true && graph[x-1][y+1]==false
		&& graph[x][y-1]==true && graph[x][y]==true && graph[x][y+1]==true
		&& graph[x+1][y-1]==false && graph[x+1][y]==true && graph[x+1][y+1]==false;
}
set<pair<int, int>> s;
int main(){
	cin>>n>>m;
	for(int i=0;i<n;i++){
		string line;cin>>line;
		for(int j=0;j<m;j++){
			if (line[j]=='*'){
				graph[i][j]=true;
				s.insert(make_pair(i, j));
			}
		}
	}
/*	for(auto [x, y]: s){
		cout<<x<<" "<<y<<endl;
	}cout<<endl;
*/	pair<int, int> cand = make_pair(-1, -1);
	for(int i=1;i<n-1;i++){
		for(int j=1;j<m-1;j++){
			if (check3x3(i, j)){
				if (cand.first!=-1){
					puts("NO");
					return 0;
				}else cand = make_pair(i, j);
			}
		}
	}
//	cout<<cand.first<<" "<<cand.second<<endl;
	if (cand.first==-1){
		puts("NO");
		return 0;
	}
	auto [cx, cy] = cand;
	s.erase(cand);
	for(int j=cy-1;j>=0 && graph[cx][j];j--) s.erase(make_pair(cx, j));
	for(int j=cy+1;j<m && graph[cx][j];j++) s.erase(make_pair(cx, j));
	for(int i=cx-1;i>=0 && graph[i][cy];i--) s.erase(make_pair(i, cy));
	for(int i=cx+1;i<n && graph[i][cy];i++) s.erase(make_pair(i, cy));
//	cout<<s.size()<<endl;
	if (s.empty()) puts("YES");
	else puts("NO");
	return 0;
}
