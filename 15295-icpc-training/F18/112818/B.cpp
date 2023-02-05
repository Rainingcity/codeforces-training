#include<cstdio>
#include<string>
using namespace std;
int n,m;
int ans;
char a[100][100];
int main(){
	scanf("%d%d", &n, &m);
	ans=0;
	for(int i=0;i<n;i++){
		scanf("%s", a[i]);
		for(int j=0;j<m-2;j++){
			if (j==0 || a[i][j-1]=='#'){
				if (a[i][j]=='.' && a[i][j+1]=='.' && a[i][j+2]=='.'){
					a[i][j]='!';
					ans++;
				}
			}
		}
	}
	for(int j=0;j<m;j++){
		for(int i=0;i<n-2;i++){
			if (i==0 || a[i-1][j]=='#'){
				if (a[i][j]=='.' && a[i+1][j]!='#' && a[i+2][j]!='#'){
					a[i][j]='!';
					ans++;
				}
			}
		}
	}
	printf("%d\n", ans);
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if (a[i][j]=='!'){
				printf("%d %d\n", i+1, j+1);
			}
		}
	}
	return 0;
}