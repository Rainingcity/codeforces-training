#include <iostream>
#include <string>
#include <vector>
using namespace	std;
int n;
vector<string> dat;
vector<vector<int>> v;
vector<bool> f;
vector<bool> vis;
int cnt[2];
void dfs(int cur){
	cnt[f[cur]]++;
	vis[cur]=true;
	for(auto& nxt: v[cur]){
		if (vis[nxt]) continue;
		dfs(nxt);
	}
}
int main(){
	cin>>n;
	f.resize(n);
	v.resize(n);
	for(int i=0;i<n;i++){
		string s;cin>>s;
		dat.push_back(s);
		bool t=0;
		for(int j=0;j<s.length();j++){
			for(int k=j+1;k<s.length();k++){
				if (s[j]>s[k]) t=!t;
			}
		}
		f[i]=t;
		for(int j=0;j<i;j++){
			if (f[i]==f[j]) continue;
			int c=0;
			for(int k=0;k<s.length();k++){
				if (s[j]!=s[k]) c++;
			}
			if (c==2){
				v[i].push_back(j);
				v[j].push_back(i);
			}
		}
	}
	int ans=0;
	for(int i=0;i<n;i++){
		if (!vis[i]){
			cnt[0]=cnt[1]=0;
			dfs(i);
			if (cnt[0]>cnt[1]) ans+=cnt[0];
			else ans+=cnt[1];
		}
	}
}
