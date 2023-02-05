#include <iostream>
#include <string>
#include <vector>
using namespace std;
int n,m,k;
string s;
vector<int> nxt{};
int main(){
	cin>>s;
	n=s.length();
	for(int i=0;i<n;i++) k+=(s[i]=='1');
	cin>>s;
	m=s.length();
	nxt.resize(m);
	nxt[0]=-1;
	int t=-1;
	for(int i=1;i<m;i++){
		while(t>=0 && s[i]!=s[t+1]) t=nxt[t];
		if (s[i]==s[t+1]) t++;
		nxt[i]=t;
	}
	string ans="";
	int i=0,cnt=0;
	for(int j=0;i+k-cnt<n && cnt<k;i++,j++){
		ans+=s[j];
		if (s[j]=='1') cnt++;
		if (j==m-1){
			j=nxt[j];
		}
	}
	for(;i<n && cnt<k;i++) ans+="1";
	for(;i<n;i++) ans+="0";
	cout<<ans<<endl;
	return 0;
}
