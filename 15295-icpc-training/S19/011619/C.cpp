#include<cstdio>
#include<cstring>
using namespace std;
int n;
int a[5010];
bool f[5010];
int main(){
	a[0]=0;
	a[1]=0;
	a[2]=1;
	for(int i=3;i<=5000;i++){
		memset(f,false,sizeof(f));
		for(int j=0,k=i-2;j<=k;j++,k--){
			f[a[j]^a[k]]=true;
		}
		a[i]=0;
		while(f[a[i]]) a[i]++;
	}
	int T;scanf("%d", &T);
	while(T--){
		scanf("%d", &n);
		if (a[n]) puts("First");
		else puts("Second");
	}
}
