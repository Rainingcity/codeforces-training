#include<cstdio>
#include<cstring>
using namespace std;
int m;
bool cyc;
bool vis[30];
int v[30][30];
int dep[30];
int ans[30],anssz;
int st[30],stn;
bool inst[30];
void dfs(int cur){
	vis[cur]=true;
	st[stn++]=cur;
	inst[cur]=true;
	int curdep=0;
	for(int i=0;i<26;i++){
		if (v[cur][i]){
			if (inst[i]){
				cyc=true;
				anssz=0;
				while(stn>0 && st[stn-1]){}
		}
	}
	--stn;
	inst[cur]=false;
}
int main(){
	int T;
	scanf("%d", &T);
	while(T--){
		cyc=false;
		memset(v,true,sizeof(v));
		memset(vis,false,sizeof(vis));
		memset(dep,0,sizeof(dep));
		anssz=0;stn=0;
		memset(ans,0,sizeof(ans));
		memset(st,0,sizeof(st));
		scanf("%d", &m);
		for(int i=0;i<m;i++){
			char s[5];scanf("%s", s);
			int x=s[0]-'a',y=s[1]-'a';
			v[x][y]=v[y][x]=false;
		}
		for(int i=0;i<26;i++){
			bool F=false;
			for(int j=0;j<26;j++){
				if (v[j][i]){
					F=true;break;
				}
			}
			if (!F){stn=0;dfs(i);}
			if (cyc) break;
		}
		for(int i=0;i<26;i++){
			if (!vis[i]){
				dfs(i);
				break;
			}
		}
		if (cyc){
			for(int x=0;x<20;x++){
				for(int y=0;y<20;y++){
					int loc=(x+y) % anssz;
					printf("%c", 'a'+ans[loc]);
				}
				puts("");
			}
			continue;
		}
		int sz=(anssz>>1);
		for(int x=0;x<sz;x++){
			for(int y=0;y<sz;y++) printf("%c", 'a'+ans[x+y]);
			puts("");
		}
	}
}
