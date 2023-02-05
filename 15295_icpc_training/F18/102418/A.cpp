#include<cstdio>
using namespace std;
int n;
int val[200100],nxt[200100];
bool vis[200100],viscur[200100];
int onstk[200100],nstk=0;
int main(){
    scanf("%d", &n);
    for(int i=0;i<n;i++) scanf("%d", val+i);
    for(int i=0;i<n;i++) scanf("%d", nxt+i),nxt[i]--;
    int ans=0;
    for(int i=0;i<n;i++){
        if (vis[i]) continue;
        nstk=0;onstk[nstk++]=i;viscur[i]=true;
        int it=nxt[i];
        while(!vis[it] && !viscur[it]){
            viscur[it]=true;
            onstk[nstk++]=it;
            it=nxt[it];
        }
        if (!vis[i]){
            int res=onstk[--nstk];
            while(onstk[nstk]!=it){
                vis[onstk[nstk]]=true;
                res=mini(res,val[osntk[--nstk]]);
            }ans+=res;
        }
        while(nstk>=0){
            vis[onstk[--nstk]]=true;
        }
    }printf("%d\n", ans);
    return 0;
}
