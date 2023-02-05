#include <iostream>
#include <vector>
using namespace std;
int n,m;
vector<vector<int>> v;
int get_j(int j, int j1, int j2){
	if (j==j1) return j2;
	else if (j==j2) return j1;
	else return j;
}
int main(){
	cin>>n>>m;
	v.resize(n);
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			int x;cin>>x;
			v[i].push_back(x);
		}
	}
	bool F=0;
	for(int i=0;i<n;i++){
		int cnt=0;
		for(int j=0;j<m && cnt<=2;j++){
			if (v[i][j]!=j+1) cnt++;
		}
		if (cnt>2){F=1;break;}
	}
	if (!F){
		cout<<"YES"<<endl;
		return 0;
	}
	for(int j1=0;j1<m;j1++){
		for(int j2=j1+1;j2<m;j2++){
			F=0;
			for(int i=0;i<n;i++){
				int cnt=0;
				for(int j=0;j<m && cnt<=2;j++){
					if (v[i][j]!=get_j(j,j1,j2)+1) cnt++;
				}
				if (cnt>2){F=1;break;}
			}
			if (!F){
				cout<<"YES"<<endl;
				return 0;
			}
		}
	}
	cout<<"NO"<<endl;
	return 0;
}
