#include <cstdio>
#include <algorithm>
using namespace std;
int n,k;
int cnt[10];
bool check(int num){
	int c=0;
	for(int i=0;i<8;i++){
		if (cnt[i]==num) c++;
		else if (cnt[i]!=0) return false;
	}
	if (c>=k) return true;
	else return false;
}
struct Cow{
	int x;
	int br;
	Cow(){}
	Cow(int _x,int _br){
		x=_x;br=_br;
	}
}a[100100];
int main(){
	scanf("%d%d", &n, &k);
	for(int i=0;i<n;i++){
		int x,y;scanf("%d%d", &x, &y);y--;
		a[i]=Cow(x,y);
	}
	for(int num=1;(num*k)<=n;num++){
		int i=0
	}
}