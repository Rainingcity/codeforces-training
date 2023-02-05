#include<cstdio>
#include<queue>
#include<cstdlib>
#include<cstring>
using namespace std;
int n;
int a[200300];
int v[200300];
bool vis[200300];
queue<int> q;
void bfs(){
	q.push(0);
	memset(vis,false,sizeof(vis));
	vis[0]=true;
	while(!q.empty()){
		int id=q.front();q.pop();
		if (!vis[v[id]]){
			a[v[id]]=a[id]+1;
			q.push(v[id]);
			vis[v[id]]=true;
		}
		if (id<n-1 && !vis[id+1]){
			a[id+1]=a[id]+1;
			q.push(id+1);
			vis[id+1]=true;
		}
		if (id>0 && !vis[id-1]){
			a[id-1]=a[id]+1;
			q.push(id-1);
			vis[id-1]=true;
		}
	}
}
int main(){
	scanf("%d", &n);
	for(int i=0;i<n;i++){
		scanf("%d", v+i);
		v[i]--;
	}
	for(int i=0;i<n;i++) a[i]=i;
	bfs();
	printf("%d", a[0]);
	for(int i=1;i<n;i++) printf(" %d", a[i]);
	puts("");
	return 0;
}