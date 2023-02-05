#include <iostream>
#include <vector>
#include <string>
using namespace std;
vector<int> cnt;
vector<int> rnd;
int main(){
	int n, m;
	cin>>n>>m;
	cnt.resize(n+1);
	rnd.resize(m+1);
	string ans="";
	int cur=1;
	for(int i=0;i<m;i++){
		int x;cin>>x;
		cnt[x]++;
		rnd[cnt[x]]++;
		if (rnd[cur]==n){
			ans+="1";
			cur++;
		}else{
			ans+="0";
		}
	}
	cout<<ans<<endl;
	return 0;
}
