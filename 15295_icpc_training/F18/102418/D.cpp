#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
const double eps=1e-12;
int n,m;
int f[200100];
bool v[2010][2010];
bool vis[1010];
struct edge{
    int v,w;
    edge(){}
    edge(int _v, int _w){
        v=_v;w=_w;
    }
}e[200100];
int con[200100];
int con2[200100];
int comp[200100];
int complen[200100];
int plen;
int dfs(int x){
    vis[x]=true;
    int ret=1;
    for(int i=1;i<=plen;i++){
        if (!vis[i] && !v[x][i]) ret+=dfs(i);
    }return ret;
}
int main(){
    scanf("%d%d", &n, &m);
    for(int i=0;i<m;i++){
        int x,y;scanf("%d%d", &x, &y);
        x--;y--;
        e[i]=edge(x,y);
        con[x]++;con[y]++;
    }
    int visitedcnt=0;
    for(int i=0;i<n;i++){
        if (con[i]*(n-con[i])>m || con[i]*2<n){
            visitedcnt++;
            comp[i]=1;
        }
    }
    memset(f,0,sizeof(f));
    for(int i=0;i<n;i++){
        if (comp[i]!=1){
            f[i]=++plen;
        }
    }
    for(int i=0;i<m;i++){
        if (comp[e[i].v]==1 && comp[e[i].w]!=1){
            con2[e[i].w]++;
        }else if (comp[e[i].v]!=1 && comp[e[i].w]==1){
            con2[e[i].v]++;
        }
    }
    complen[1]=visitedcnt;
    memset(v,false,sizeof(v));
    for(int i=0;i<m;i++){
        if (f[e[i].v]==0 && f[e[i].w]!=0){
            if (con2[e[i].w]>=visitedcnt) v[f[e[i].v]][f[e[i].w]]=v[f[e[i].w]][f[e[i].v]]=true;
        }else if (f[e[i].w]==0 && f[e[i].v]!=0){
            if (con2[e[i].v]>=visitedcnt) v[f[e[i].v]][f[e[i].w]]=v[f[e[i].w]][f[e[i].v]]=true;
        }else{
            v[f[e[i].v]][f[e[i].w]]=v[f[e[i].w]][f[e[i].v]]=true;
        }
    }
    memset(vis,false,sizeof(vis));
    if (visitedcnt!=0) complen[1]+=dfs(0)-1;
    int curcomp=2;
    if (visitedcnt==0) curcomp=1;
    for(int i=1;i<=plen;i++){
        if (!vis[i]){
            int curcnt=dfs(i);
            complen[curcomp++]=curcnt;
        }
    }
    sort(complen+1,complen+curcomp);
    printf("%d\n%d", curcomp-1, complen[1]);
    for(int i=2;i<curcomp;i++){
        printf(" %d", complen[i]);
    }puts("");
    return 0;
}
