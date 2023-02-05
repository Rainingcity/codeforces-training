#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
typedef pair<int,int> pii;
int mini(int x,int y){return x<y?x:y;}
int n,m;
int S,T;
int cap[210][210];
int flow[210][210];
int aug[210],previ[210];
void maxflow(){
    while(true){
        memset(aug,0,sizeof(aug));
        memset(previ,-1,sizeof(previ));
        queue<pii> q;
        aug[S]=1000;
        previ[S]=-1;
        q.push(make_pair(S,aug[S]));
        while(!q.empty()){
            pii curpair=q.front();
            q.pop();
            int cur=curpair.first,curaug=curpair.second;
            for(int i=1;i<=T;i++){
                if (cap[cur][i]==0 && cap[i][cur]==0) continue;
                if (previ[i]!=-1) continue;
                if (cap[cur][i]>flow[cur][i]){
                    int tt=mini(curaug,cap[cur][i]-flow[cur][i]);
                    aug[i]=tt;previ[i]=cur;
                    q.push(make_pair(i,tt));
                }
            }
            if (aug[T]) break;
        }
        if (aug[T]==0) break;
        int Aug=aug[T],cur=T;
        while(cur!=-1){
            int p=previ[cur];
            flow[p][cur]+=Aug;
            flow[cur][p]-=Aug;
            cur=p;
        }
    }
}
int main(){
    scanf("%d%d", &n, &m);
    S=0;T=2*n+1;
    for(int i=0;i<n;i++){
        scanf("%d", &cap[S][i+1]);
        cap[i+1][i+n+1]=cap[S][i+1];
    }
    for(int i=0;i<n;i++){
        scanf("%d", &cap[i+n+1][T]);
        cap[i+1][i+n+1]=mini(cap[i+1][i+n+1],cap[i+n+1][T]);
    }
    for(int i=0;i<m;i++){
        int x,y;scanf("%d%d", &x, &y);
        cap[x][y+n]=mini(cap[S][x],cap[y+n][T]);
        cap[y][x+n]=mini(cap[S][y],cap[x+n][T]);
    }
    maxflow();
    bool F=true;
    for(int i=1;i<=n;i++) if (flow[S][i]!=cap[S][i]) F=false;
    for(int i=n+1;i<T;i++) if (flow[i][T]!=cap[i][T]) F=false;
    if (!F) puts("NO");
    else{
        puts("YES");
        for(int i=1;i<=n;i++){
            for(int j=n+1;j<T;j++){
                if (j!=n+1) printf(" ");
                printf("%d", flow[i][j]);
            }puts("");
        }
    }
    return 0;
}
