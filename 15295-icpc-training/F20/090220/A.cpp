#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
int n;
string s[40];
void solve(){
	bool F=true;
	char mx=(n<=10?'0'+n:'A'+(n-10));
	for(int i=0;i<n;i++) cin>>s[i];
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if (s[i][j]<'0' || (s[i][j]>'9' && s[i][j]<'A') || s[i][j]>'Z'){
				puts("No");
				return;
			}
			if (s[i][j]>=mx){
				puts("No");
				return;
			}
		}
	}
	for(int i=0;i<n;i++){
		vector<bool> vr(128, false);
		vector<bool> vc(128, false);
		for(int j=0;j<n;j++){
			if (vr[s[i][j]]){
				puts("No");
				return;
			}else vr[s[i][j]]=true;
			if (vc[s[j][i]]){
				puts("No");
				return;
			}else vc[s[j][i]]=true;
		}
	}
	for(int i=0;i<n;i++){
		if (i<10){
			if (s[0][i]!=i+'0' || s[i][0]!=i+'0'){
				puts("Not Reduced");
				return;
			}
		}else{
			if (s[0][i]!=(i-10)+'A' || s[i][0]!=(i-10)+'A'){
				puts("Not Reduced");
				return;
			}
		}
	}
	puts("Reduced");
	return;
}

int main(){
	while((scanf("%d", &n))!=EOF){
		solve();
	}
}
