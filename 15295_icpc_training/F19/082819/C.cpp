#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
const double eps = 1e-8;
int n;
double m;
vector<double> v;
vector<vector<double>> ans;
int main(){
	cin>>n>>m;
	for(int i=0;i<n;i++){
		int x;cin>>x;v.push_back(x);
	}
	sort(v.begin(), v.end());
	int cnt=1;
	while(m>=0.01+eps){
		int it=n-1;
		while(it>=0){
			double cur=v[it];
			vector<double> ansv{};
			ansv.resize(cnt, cur);
			while(m*cnt>=cur){
				m-=cur/cnt;
				ans.push_back(ansv);
			}
			it--;
		}
		cnt++;
	}
	cout<<ans.size()<<endl;
	for(auto l: ans){
		cout<<l.size();
		for(auto e: l){
			cout<<" "<<(int)e;
		}
		cout<<endl;
	}
	return 0;
}
