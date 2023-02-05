#include <iostream>
#include <string>
#include <vector>
using namespace std;
int n;
string s;
vector<int> nxt{};
vector<int> first{};
void GetNextval(){
	nxt[0] = -1;
	int k = -1;
	int j = 0;
	while (j < n - 1)
	{
		if (k == -1 || s[j] == s[k])
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
int main(){
	cin>>s;s+="#";
	n=s.length();
	nxt.resize(n+1);
	first.resize(n+1,-1);
	GetNextval();
	for(int i=0;i<n;i++){
		if (nxt[i]==-1) continue;
		if (first[nxt[i]]==-1) first[nxt[i]]=i;
	}
	int ans=-1;
	if (nxt[n-1]<1) cout<<"Just a legend"<<endl;
	else if (n-1>first[nxt[n-1]]){
		for(int i=0;i<nxt[n-1];i++) cout<<s[i];
		cout<<endl;
	}else if (nxt[nxt[n-1]]>0){
		for(int i=0;i<nxt[nxt[n-1]];i++) cout<<s[i];
		cout<<endl;
	}else cout<<"Just a legend"<<endl;
	return 0;
}
