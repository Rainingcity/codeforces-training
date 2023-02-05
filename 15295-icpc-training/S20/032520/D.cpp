#include <iostream>
#include <string>
#include <vector>
using namespace std;
void GetNextval(vector<int>& nxt, int n, string ss){
	nxt[0] = -1;
	int k = -1;
	int j = 0;
	while (j < n - 1)
	{
		if (k == -1 || ss[j] == ss[k])
		{
			++j;
			++k;
			nxt[j] = k;
		}
		else
		{
			k = nxt[k];
		}
	}
}
string s,s1,s2;
int n,n1,n2;
vector<int> nxt1,nxt2;
vector<int> v1,v2;
int main(){
	cin>>s>>s1>>s2;
	n=s.length();
	n1=s1.length();
	n2=s2.length();
	s1+="#";s2+="#";
	nxt1.resize(n1+1);
	nxt2.resize(n2+1);
	GetNextval(nxt1,n1+1,s1);
	GetNextval(nxt2,n2+1,s2);
	int j=0;
	for(int i=0;i<n;i++){
		if (j==n1) v1.push_back(i-n1);
		if (s[i]==s1[j]) j++;
		else{
			while(j!=-1 && s[i]!=s1[j]){
				j=nxt1[j];
			}
			j++;
		}
	}
	if (j==n1) v1.push_back(n-n1);
	j=0;
	for(int i=0;i<n;i++){
		if (j==n2) v2.push_back(i-n2);
		if (s[i]==s2[j]) j++;
		else{
			while(j!=-1 && s[i]!=s2[j]){
				j=nxt2[j];
			}
			j++;
		}
	}
	if (j==n2) v2.push_back(n-n2);
	if (v1.size()==0 || v2.size()==0){
		cout<<0<<endl;
		return 0;
	}
	// for(auto& x: v1) cout<<x<<" ";
	// cout<<endl;
	// for(auto& y: v2) cout<<y<<" ";
	// cout<<endl;
	j=0;
	int ans=0;
	int m=v2.size();
	for(auto& x: v1){
		while(j<m && !(x<=v2[j] && x+n1<=v2[j]+n2)) j++;
		ans+=(m-j);
	}
	cout<<ans<<endl;
	return 0;
}
