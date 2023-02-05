#include<cstdio>
using namespace std;
bool pos[100100];
int cnt[100100];
int a[100100];
bool b[100100];
int n,m;
int main(){
	scanf("%d%d", &n, &m);
	int sum=0;
	for(int i=0;i<n;i++){
		char op;
		int x;
		op = getchar();
		op = getchar();
		scanf("%d", &x);
		a[i+1]=x;
		if (op=='+'){
			b[i+1]=1;
			cnt[x]++;
		}else{
			b[i+1]=0;
			cnt[x]--;
			sum++;
		}
	}
	int res=0;
	for(int i=1;i<=n;i++){
		int cur = sum + cnt[i];
		if (cur==m){
			pos[i]=true;
			res++;
		}
	}
	if (res==1){
		for(int i=1;i<=n;i++){
			if (pos[a[i]]^b[i]) puts("Lie");
			else puts("Truth");
		}
	}else{
		for(int i=1;i<=n;i++){
			if (pos[a[i]]) puts("Not defined");
			else if (b[i]) puts("Lie");
			else puts("Truth");
		}
	}
	return 0;
}
