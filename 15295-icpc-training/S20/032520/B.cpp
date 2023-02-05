#include <iostream>
#include <string>
#include <vector>
using namespace std;
int n;
string s;
vector<int> nxt;
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
	cin>>s;
	n=s.length();
	nxt.resize(n+1);
	GetNextval();
	// for(int i=0;i<n;i++) cout<<nxt[i]<<" ";
	// 	cout<<endl;
	cout<<n/(n-1-nxt[n-1])<<endl;
	return 0;
}
