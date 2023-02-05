#include <iostream>
#include <string>
using namespace std;

int n,m,k;

int main(){
	cin>>n>>m>>k;
	string s;
	int cnt=0;
	for(int i=0;i<n;i++){
		cin>>s;
		for(int j=0;j<m;j++) if (s[j]=='1') cnt++;
	}
	if (cnt>=2*k) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
}
