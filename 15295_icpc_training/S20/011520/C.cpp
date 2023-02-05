#include <iostream>
#include <vector>
using namespace std;
int n;
vector<int> v[2];
bool cur=1,nxt=0;
int main(){
	cin>>n;
	int k=1;
	for(int i=0;i<n;i++){
		int x;cin>>x;
		v[cur].push_back(x);
		while(k<x) k<<=1;
	}
	int ans=0;
	while(k!=0){
		v[nxt].clear();
		// cout<<k<<endl;
		for(auto it=v[cur].begin();it!=v[cur].end();it++){
			if (((*it)&k)!=0){
				v[nxt].push_back(*it);
				// cout<<"inserted: "<<*it<<endl;
			}
		}
		if (v[nxt].size()>=2){
			ans+=k;
			cur=nxt;
			nxt=!nxt;
		}
		k>>=1;
	}
	cout<<ans<<endl;
	return 0;
}
