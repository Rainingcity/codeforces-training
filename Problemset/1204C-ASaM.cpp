/*
 * Codeforces 1204C
 * Anna, Svyatoslav and Maps
 */

#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
const int INF=1000000007;
int n,m;
vector<vector<int>> v;
void forward(int& prev, int& cur, int& next, vector<int>& ans){
	if (cur!=-1) ans.push_back(cur+1);
	prev=cur;cur=next;
}
int main(){
	cin>>n;
	v.resize(n);
	for(int i=0;i<n;i++) v[i].resize(n);
	for(int i=0;i<n;i++){
		string x;cin>>x;
		for(int j=0;j<n;j++){
			v[i][j]=x[j]-'0';
			if (i!=j && v[i][j]==0) v[i][j]=INF;
		}
	}
	for(int k=0;k<n;k++){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if (v[i][k]+v[k][j]<v[i][j]) v[i][j]=v[i][k]+v[k][j];
			}
		}
	}
/*	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<v[i][j];
		}cout<<endl;
	}*/
	cin>>m;
	vector<int> ans{};
	int p1=-1, p2=-1, x;
	for(int i=0;i<m;i++){
		cin>>x;x--;
		if (p1==-1) forward(p1, p2, x, ans);
		else{
//			cout<<v[p1][p2]<<" "<<v[p2][x]<<" "<<v[p1][x]<<endl;
			if (v[p1][p2]+v[p2][x]==v[p1][x]){
				p2=x;
			}else{
				forward(p1, p2, x, ans);
			}
		}
	}
	ans.push_back(x+1);
	cout<<ans.size()<<endl;
	cout<<ans[0];
	for(int i=1;i<ans.size();i++) cout<<" "<<ans[i];
	cout<<endl;
	return 0;
}
