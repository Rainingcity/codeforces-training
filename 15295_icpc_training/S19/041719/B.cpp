#include<cstdio>
#include<cstring>
using namespace std;
int nim[200100];
int cnt[200100];

inline void swap(int& a, int& b){
	a=a^b;
	b=a^b;
	a=a^b;
}

int main(){
	int a,b,c,k;
	scanf("%d%d%d%d", &a, &b, &c, &k);
	while(!(a==0 && b==0 && c==0 && k==0)){
		memset(nim,0,sizeof(nim));
		memset(cnt,0,sizeof(cnt));
		if (a>b) swap(a,b);
		if (a>c) swap(a,c);
		if (b>c) swap(b,c);
		if (b==c) c=0;
		if (a==b) b=0;
		int sz;scanf("%d", &sz);
		cnt[0]=1;int curans=1;
		for(int i=1;i<=sz;i++){
			int curnim=curans;
			if (a!=0 && i>=a) cnt[nim[i-a]]--;
			if (b!=0 && i>=b) cnt[nim[i-b]]--;
			if (c!=0 && i>=c) cnt[nim[i-c]]--;
			if (a!=0 && i>=a && cnt[nim[i-a]]==0 && nim[i-a]<curnim) curnim=nim[i-a];
			if (b!=0 && i>=b && cnt[nim[i-b]]==0 && nim[i-b]<curnim) curnim=nim[i-b];
			if (c!=0 && i>=c && cnt[nim[i-c]]==0 && nim[i-c]<curnim) curnim=nim[i-c];
			if (a!=0 && i>=a) cnt[nim[i-a]]++;
			if (b!=0 && i>=b) cnt[nim[i-b]]++;
			if (c!=0 && i>=c) cnt[nim[i-c]]++;
			nim[i]=curnim;cnt[nim[i]]++;
			while(cnt[curans]) curans++;
		}
		printf("%d", nim[sz]);
		for(int i=1;i<k;i++){
			scanf("%d", &sz);
			printf(" %d", nim[sz]);
		}puts("");
		scanf("%d%d%d%d", &a, &b, &c, &k);
	}
}
