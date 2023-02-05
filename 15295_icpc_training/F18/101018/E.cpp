#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
int mini(int x,int y){return x<y?x:y;}
int maxi(int x,int y){return x>y?x:y;}
int T;
int n,m;
int le[60],ri[60];
bool vis[110];
int res=0,reslist[110];
bool f[110][110];
void dfs(int x){
    if (vis[x]) return;
    vis[x]=1;
    if (x>=n){
        if (res==-1 || reslist[res]>reslist[x-n]){
            res=x-n;
        }
        for(int i=0;i<n;i++){
            if (f[x][i]) dfs(i);
        }
    }else{
        for(int i=n;i<T;i++){
            if (f[x][i]) dfs(i);
        }
    }
}
int main(){
    scanf("%d%d", &n, &m);
    T=2*n+1;
    for(int i=0;i<n;i++){
        le[i]=1;ri[i]=n;
    }
    for(int i=0;i<m;i++){
        int op,l,r,x;scanf("%d%d%d%d", &op, &l, &r, &x);
        if (op==1){
            for(int i=l-1;i<r;i++) le[i]=maxi(le[i],x);
        }else{
            for(int i=l-1;i<r;i++) ri[i]=mini(x,ri[i]);
        }
    }
    for(int i=0;i<n;i++){
        if (le[i]>ri[i]){
            puts("-1");
            return 0;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=le[i];j<=ri[i];j++){
            f[i][j+n-1]=f[j+n-1][i]=1;
        }
    }
    for(int i=0;i<n;i++){
        memset(vis,0,sizeof(vis));
        res=-1;
        dfs(i);
        reslist[res]++;
    }
    int ans=0;
    for(int i=0;i<n;i++){
        ans+=reslist[i]*reslist[i];
    }printf("%d\n", ans);
    return 0;
}
