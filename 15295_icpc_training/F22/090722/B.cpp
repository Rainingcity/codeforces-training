#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
vector<vector<bool>> row{};
vector<vector<bool>> col{};
int n,m,k;
int main(){
	cin>>n>>m>>k;
	row.resize(n);
	col.resize(m);
	for(int i=0;i<n;i++) row[i].resize(m);
	for(int j=0;j<m;j++) col[j].resize(n);

	int sum=0;
	for(int i=0;i<n;i++){
		string s;cin>>s;
		for(int j=0;j<m;j++){
			if (s[j]=='.'){
				row[i][j]=col[j][i]=true;
				sum++;
			}else row[i][j]=col[j][i]=false;
		}
	}

	if (k==1){
		cout<<sum<<endl;
		return 0;
	}

	int ans=0;
	for(int i=0;i<n;i++){
		int cnt=0;
		for(int j=0;j<m;j++){
			if (row[i][j]) cnt++;
			else{
				if (cnt>=k) ans+=cnt-k+1;
				cnt=0;
			}
		}
		if (cnt>=k) ans+=cnt-k+1;
	}

	for(int j=0;j<m;j++){
		int cnt=0;
		for(int i=0;i<n;i++){
			if (col[j][i]) cnt++;
			else{
				if (cnt>=k) ans+=cnt-k+1;
				cnt=0;
			}
		}
		if (cnt>=k) ans+=cnt-k+1;
	}

	cout<<ans<<endl;
	return 0;
}
