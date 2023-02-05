#include<cstdio>
#include<cstring>
#include<map>
using namespace std;
int n;
map<int,int> a;
int ans[200100];
int ansl[200100];
void print(int pos, int l){
	if (ans[pos]==-1){
		printf("%d\n%d", l, pos+1);
		return;
	}
	print(ans[pos],l+1);
	printf(" %d", pos+1);
}
int main(){
	scanf("%d", &n);
	int mxans=0,ed=-1;
	for(int i=0;i<n;i++){
		int x;scanf("%d", &x);
		ans[i]=-1;ansl[i]=1;
		if (a.find(x-1)!=a.end()){
			ans[i]=a[x-1];
			ansl[i]=ansl[a[x-1]]+1;
		}
		a[x]=i;
		if (mxans<ansl[i]){
			mxans=ansl[i];
			ed=i;
		}
	}
	print(ed,1);
	puts("");
	return 0;
}