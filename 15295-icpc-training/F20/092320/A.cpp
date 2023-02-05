#include <iostream>
#include <vector>
using namespace std;
int n;
vector<int> v;
vector<int> f;
vector<int> ps;
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		int x;cin>>x;
		v.push_back(x);
	}
	f.resize(n+1);
	ps.resize(n);ps[n-1]=v[n-1];
	for(int i=n-2;i>=0;i--) ps[i]=v[i]+ps[i+1];
	f[n-1]=v[n-1];
	for(int i=n-2;i>=0;i--){
		f[i]=max(f[i+1], ps[i]-f[i+1]);
	}
	cout<<ps[0]-f[0]<<" "<<f[0]<<endl;
	return 0;
}
