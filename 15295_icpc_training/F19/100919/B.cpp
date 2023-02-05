#include <iostream>
#include <vector>
using namespace std;
int r,m;
vector<bool> f;
vector<int> v;
int main(){
	cin>>r>>m;
	if (r==m){
		cout<<1<<endl;
		return 0;
	}
	f.resize(m+10000);
	size_t i=2;
	f[r]=true;
	size_t cur=1;
	size_t last=r;
	v.push_back(r);
	while(f[cur]) cur++;
	for(;i<=10000;i++){
		v.push_back(last+cur);
		if (last+cur<=m) f[last+cur]=true;
		f[cur]=true;
		for(size_t j=0;j+2<v.size();j++){
			int ans=last+cur-v[j];
			if (ans<=m) f[ans]=true;
		}
		last+=cur;
		while(f[cur]) cur++;
		if (f[m]) break;
	}
	cout<<i<<endl;
	return 0;
}
