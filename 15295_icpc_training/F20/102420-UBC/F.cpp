#include <iostream>
#include <vector>
using namespace std;
int n;
vector<vector<bool>> v{};
vector<int> nbrs{};
int main(){
	cin>>n;
	v.resize(n);
	for(int i=0;i<n;i++) v[i].resize(n);
	for(int i=0;i<n;i++){
		cout<<"? 1 "<<i+1<<endl;
		fflush(stdout);
		int x;cin>>x;
		if (x==-1) return 0;
		nbrs.push_back(x);
	}
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			cout<<"? 2 "<<i+1<<" "<<j+1<<endl;
			fflush(stdout);
			int x;cin>>x;
			if (x==-1) return 0;
			v[i][j]=v[j][i]=(nbrs[i]+nbrs[j]!=x);
		}
	}
	cout<<"!"<<endl;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if (j) cout<<" ";
			cout<<v[i][j];
		}
		cout<<endl;
	}
	cout<<endl;
	fflush(stdout);
	return 0;
}
