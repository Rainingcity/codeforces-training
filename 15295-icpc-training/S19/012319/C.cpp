#include<cstdio>
#include<cstring>
using namespace std;
char s[100100];
int main(){
	scanf("%s", s);
	int n=strlen(s);
	int cnt=0;
	int maxcnt=0;
	int cntupper=0;
	for(int i=0;i<n;i++){
		if ('a'<=s[i] && s[i]<='z') cnt--;
		else{
			cntupper++;
			cnt++;
			if (cnt>maxcnt) maxcnt=cnt;
		}
	}
	printf("%d\n", cntupper-maxcnt);
	return 0;
}