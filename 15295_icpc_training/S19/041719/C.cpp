#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
typedef long double ld;
int n;
int nim[1001000];
int sq(int x){return x*x;}
int cnt[20];
struct RECORD{
	int st;
	int ed;
	int id;
	int ans;
	RECORD(){st=ed=id=ans=0;}
	RECORD(int i,int x,int y){st=x;ed=y;id=i;ans=0;}
}dat[100100];
bool cmp1(RECORD x, RECORD y){
	if (x.st!=y.st) return x.st<y.st;
	if (x.ed!=y.ed) return x.ed<y.ed;
	return x.id<y.id;
}
bool cmp2(RECORD x, RECORD y){
	return x.id<y.id;
}
int main(){
	nim[0]=nim[1]=nim[2]=nim[3]=0;
	int st=2,ed=2;cnt[0]=1;
	for(int i=4;i<890000;i++){
		if (i>sq(sq(st))){
			cnt[nim[st]]--;
			st++;
		}
		if (i>=sq(ed+1)){
			ed++;
			cnt[nim[ed]]++;
		}
		int nm;
		for(nm=0;nm<15 && cnt[nm];nm++);
		nim[i]=nm;
	}
	int ans=0;
	scanf("%d", &n);
	for(int i=0;i<n;i++){
		ll sz;scanf("%I64d", &sz);
		if (sz<890000){
			ans^=nim[sz];
			i--;n--;
			continue;
		}
		int st=(int)ceil(sqrt(sqrt((ld)sz)));
		int ed=(int)floor(sqrt((ld)sz));
		dat[i]=RECORD(i, st, ed);
	}
	if (n==0){
		if (ans==0) puts("Rublo");
		else puts("Furlo");
		return 0;
	}
	memset(cnt,0,sizeof(cnt));
	sort(dat,dat+n,cmp1);
	st=dat[0].st;ed=dat[0].ed;
	for(int i=st;i<=ed;i++) cnt[nim[i]]++;
	int nm;
	for(nm=0;nm<15 && cnt[nm];nm++);
	dat[0].ans=nm;
	ans^=nm;
	for(int i=1;i<n;i++){
		if (dat[i].ed>ed){
			while(ed<dat[i].ed){
				ed++;
				cnt[nim[ed]]++;
			}
		}
		if (dat[i].st>st){
			while(st<dat[i].st){
				cnt[nim[st]]--;
				st++;
			}
		}
		for(nm=0;nm<15 && cnt[nm];nm++);
		dat[i].ans=nm;
		ans=ans^nm;
	}
	if (ans==0) puts("Rublo");
	else puts("Furlo");
	return 0;
}
