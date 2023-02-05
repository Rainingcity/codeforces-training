#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int n;vector<int> v;
vector<char> ans;
int first[128];
int main(){
	cin>>n;
	ans.resize(n);
	for(int i=0;i<n;i++){
		int x;cin>>x;v.push_back(x-1);
	}
	char c='a';
	for(int i=n-1;i>=0;i--){
		if (v[i]<=i){
			puts("-1");
			return 0;
		}
		if (v[i]==n){
			if (c>'z'){
				puts("-1");
				return 0;
			}
			first[c]=i;
			ans[i]=c;
			c++;
		}else if (v[i]<n){
			if (first[ans[v[i]]]!=v[i]){
				puts("-1");
				return 0;
			}
			first[ans[v[i]]]=i;
			ans[i]=ans[v[i]];
		}else{
			puts("-1");
			return 0;
		}
	}
	for(int i=0;i<n;i++) cout<<ans[i];
	cout<<endl;
	return 0;
}
