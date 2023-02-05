#include <iostream>
using namespace std;
int n;
vector<int> v;
bool check(int x){
	pair<int,int> cur(-20000,20000);
	for(int i=1;i<n;i++){
		pair<int,int> nint=make_pair(v[i]-v[i-1])
	}
}
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		int x;cin>>x;
		v.push_back(x);
	}
	double l=0.0, r=300000.0;
	while(l+1e-7<r){
		double mid=(l+r)/2.0;
		if (check(mid))
	}
}
