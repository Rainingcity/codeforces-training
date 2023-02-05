/*
 * Codeforces 1203D2
 * Remove the String (hard version)
 */

#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int maxi(int x, int y){return x<y?y:x;}
string s,t;
int n,m;
vector<int> v;
int main(){
	cin>>s>>t;
	n=s.length();m=t.length();
	int i, j=0;
	for(i=0;i<n && j<m;i++){
		if (s[i]==t[j]){
			v.push_back(i);
			j++;
		}
	}
	int mx=maxi(v[0], n-v[m-1]-1);
	for(int k=1;k<m;k++){
		mx=maxi(v[k]-v[k-1]-1, mx);
	}
	i=n-1;
	int prev=n;
	for(j=m-1;j>=0 && i>=0;j--){
		int pos=v[j];
		v.pop_back();
		while(i>pos && s[i]!=t[j]) i--;
		mx=maxi(mx, prev-i-1);
		mx=maxi(mx, (j>0?i-v[j-1]-1:i));
		prev=i;i--;
	}
	cout<<mx<<endl;
	return 0;
}
