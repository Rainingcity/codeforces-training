#include <iostream>
#include <vector>
#include <string>
using namespace std;
int n,m,mu;
vector<vector<int>> M;
vector<int> v,w;
string s;
int main(){
	cin>>n;M.resize(n);
	for(int i=0;i<n;i++){
		M[i].resize(n);
		for(int j=0;j<n;j++) cin>>M[i][j];
	}
	getline(cin, s);
	getline(cin, s);
	m=s.length();
	mu=((m+n-1)/n)*n;
	v.resize(mu);
	w.resize(mu);
	for(int i=0;i<m;i++){
		if ('A'<=s[i] && s[i]<='Z') v[i] = s[i]-'A';
		else if ('0'<=s[i] && s[i]<='9') v[i] = s[i]-'0'+26;
		else v[i]=36;
	}
	for(int i=m;i<mu;i++) v[i]=36;
	for(int i=0;i<mu;i+=n){
		for(int j=0;j<n;j++){
			for(int k=0;k<n;k++){
				w[i+j]=(w[i+j]+M[j][k]*v[i+k])%37;
			}
		}
	}
	for(int i=0;i<mu;i++){
		if (w[i]<26) cout<<(char)(w[i]+'A');
		else if (w[i]==36) cout<<" ";
		else cout<<w[i]-26;
	}
	cout<<endl;
	return 0;
}
