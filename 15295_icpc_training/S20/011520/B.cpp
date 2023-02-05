#include <iostream>
#include <vector>
using namespace std;
int n,m;
vector<int> rows,cols;
vector<vector<int>> dat;
void Swap(int& x, int& y){
	int t=x;x=y;y=t;
}
int main(){
	cin>>n>>m;
	rows.resize(n);cols.resize(n);
	for(int i=0;i<n;i++){rows[i]=i;}
	for(int j=0;j<n;j++){cols[j]=j;}
	dat.resize(n);
	for(int i=0;i<n;i++){
		dat[i].clear();
		for(int j=0;j<n;j++){
			int x;cin>>x;
			dat[i].push_back(x);
		}
	}
	for(int i=0;i<m;i++){
		char op;int x, y;cin>>op>>x>>y;
		x--;y--;
		if (op=='A'){
			cout<<dat[rows[x]][cols[y]]<<endl;
		}else if (op=='R'){
			Swap(rows[x],rows[y]);
		}else{
			Swap(cols[x],cols[y]);
		}
	}
	return 0;
}
