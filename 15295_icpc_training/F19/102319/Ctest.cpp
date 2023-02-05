#include <iostream>
#include <vector>
using namespace std;
const int N=100000;
bool f[100100];
vector<int> v;
bool f2[10010];
int main(){
	int m;cin>>m;
	for(int i=2;i<=N;i++){
		if (f[i]==0) v.push_back(i);
		for(int j=0;j<v.size();j++){
			if (i*v[j]>N) break;
			f[i*v[j]]=1;
			if (i%v[j]==0) break;
		}
	}
	for(int i=0;i<v.size();i++){
		f2[v[i]/m]=1;
	}
	for(int i=0;i<=N/m;i++){
		if (!f2[i]) cout<<i<<endl;
	}
	return 0;
}
