#include<iostream>
#include<string>
using namespace std;
string a,b,v;
int n,m,k;
int pat[110];
string dp[110][110][110];

void calc_pat(){
	pat[0]=-1;
	int j=0,t=-1;
	while(j<k-1){
		if (t==-1 || v[j]==v[t]){
			++j;++t;
			pat[j]=t;
		}else{
			t=pat[t];
		}
	}
}

int main(){
	cin>>a>>b>>v;
	n=a.length();m=b.length();k=v.length();
	calc_pat();
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			for(int l=0;l<k;l++){
				if (dp[i-1][j][l].length()>dp[i][j][l].length())
					dp[i][j][l]=dp[i-1][j][l];
				if (dp[i][j-1][l].length()>dp[i][j][l].length())
					dp[i][j][l]=dp[i][j-1][l];
			}
			if (a[i-1]==b[j-1]){
				char cur = a[i-1];
				for(int p=0;p<k;p++){
					string x = dp[i-1][j-1][p]+cur;
					int l=p;
					while(l!=-1 && v[l]!=cur) l=pat[l];
					if (l<k-1 && x.length()>dp[i][j][l+1].length()) dp[i][j][l+1]=x;
				}
			}
		}
	}
	string ans = "";
	for(int i=0;i<k;i++) if (dp[n][m][i].length()>ans.length()) ans=dp[n][m][i];
	if (ans=="") puts("0");
	else cout<<ans<<endl;
	return 0;
}
