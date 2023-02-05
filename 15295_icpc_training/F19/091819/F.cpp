#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>
using namespace std;
int n;
vector<int> v;
struct info{
	int last;
	int mx;
	info(){last=-1;mx=0;}
	info(int x, int y){last=x;mx=y;}
};
map<int, info> mp{};
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		int x;cin>>x;v.push_back(x);
		if (mp.find(x)==mp.end()){
			mp.emplace(x,info(i, i));
		}else{
			mp.at(x).mx=max(mp.at(x).mx, i-mp.at(x).last-1);
			mp.at(x).last=i;
		}
	}
	int ans=0;
	for(auto& [x, it]: mp){
		it.mx=max(it.mx, n-it.last-1);
		ans=max(ans, it.mx);
	}
	cout<<ans+1<<endl;
}
