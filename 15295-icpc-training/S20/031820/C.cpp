#include <iostream>
#include <string>
#include <vector>
using namespace std;
int n;
int f[2010][2010];
vector<int> cnt;
int main(){
	cin>>n;
	cnt.resize(n,0);
	for(int i=0;i<n;i++){
		string s;cin>>s;
		for(int j=0;j<n;j++){
			if (s[j]=='Y') f[i][j]=1,cnt[i]++;
			else f[i][j]=0;
		}
	}
	int ans=0;
	for(int i=0;i<n;i++){
		ans+=cnt[i]*(n-1-cnt[i]);
	}
	int ans2=0;
	for(int i=0;i<n;i++){
		ans2+=cnt[i]*(cnt[i]-1)/2+(n-1-cnt[i])*(n-2-cnt[i])/2;
	}
	cout<<(ans-ans2/2)/3<<endl;
	return 0;
}
