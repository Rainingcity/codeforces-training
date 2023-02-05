#include <iostream>
#include <vector>
using namespace std;
int n,m;
string S,T;
vector<int> v,w;
vector<vector<int>> A,B;
int main(){
	cin>>n;
	getline(cin, S);
	getline(cin, S);
	getline(cin, T);
	m=S.length();
	v.resize(m);w.resize(m);
	for(int i=0;i<m;i++){
		if ('A'<=S[i] && S[i]<='Z') v[i] = S[i]-'A';
		else if ('0'<=S[i] && S[i]<='9') v[i] = S[i]-'0'+26;
		else v[i]=36;
	}
	for(int i=0;i<m;i++){
		if ('A'<=T[i] && T[i]<='Z') w[i] = T[i]-'A';
		else if ('0'<=T[i] && T[i]<='9') w[i] = T[i]-'0'+26;
		else w[i]=36;
	}
	A.resize(m);
	for(int i=0;i<(m/n);i++){
		for(int j=0;j<n;j++){
			A[i+j].resize(n+1);
			for(int k=0;k<n;k++){
				A[i+j][k]=v[i*n+k];
			}
		}
	}
	for(int i=0;i<n;i++){
	}
}
