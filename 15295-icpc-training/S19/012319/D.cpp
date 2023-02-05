#include<cstdio>
#include<cstring>
using namespace std;
char s[100100];
int n;
int presum[100100];
int main(){
	scanf("%s", s);
	n=strlen(s);
	for(int i=1;i<n;i++){
		presum[i]=presum[i-1]+(s[i-1]==s[i]);
	}
	int q=0;scanf("%d", &q);
	while(q--){
		int x,y;scanf("%d%d", &x, &y);
		printf("%d\n", presum[y-1]-presum[x-1]);
	}
	return 0;
}