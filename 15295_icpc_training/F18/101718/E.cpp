#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
int n;
int ord[100100];
int rev[100100];
int a[100100];
int r[100100];
int ap[100100];
int rp[100100];
int left[100100];
int right[100100];
bool cmp(int x,int y){
    return a[x]<a[y];
}
int leftBinSearch(int tar,int rBorder){
    int le=0,ri=rBorder;
    while(le<ri){
        int mid=(le+ri)>>1;
        if (ap[mid]==tar) return mid;
        if (ap[mid]>tar) ri=mid;
        else le=mid+1;
    }return le;
}
int rightBinSearch(int tar,int lBorder){
    int le=lBorder,ri=n-1;
    while(le<ri){
        int mid=(le+ri+1)>>1;
        if (ap[mid]==tar) return mid;
        if (ap[mid]>tar) ri=mid-1;
        else le=mid;
    }return le;
}
int stk[100100],nstk=0;
int pos[100100];
int low[100100];
int onstk[100100];
int c[100100];
int ansl[100100];
int ansr[100100];
int comp=0;
void dfs(int cur){
    pos[cur]=low[cur]=nstk;
    stk[nstk++]=cur;
    onstk[cur]=true;
    for(int i=left[cur];i<=right[cur];i++){
        if (pos[i]==-1){
            dfs(i);
            if (low[i]<low[cur]) low[cur]=low[i];
        }else if (onstk[i]){
            if (pos[i]<low[cur]) low[cur]=pos[i];
        }
    }
    if (low[cur]==pos[cur]){
        int pp=stk[--nstk];
        comp++;
        c[pp]=comp;
        onstk[pp]=false;
        while(pp!=cur){
            pp=stk[--nstk];
            c[pp]=comp;
            onstk[pp]=false;
        }
    }
}
bool vis[100100];
int mini(int x,int y){return x<y?x:y;}
int maxi(int x,int y){return x>y?x:y;}
void dfs2(int cur){
    vis[cur]=true;
    ansl[c[cur]]=mini(ansl[c[cur]],left[cur]);
    ansr[c[cur]]=maxi(ansr[c[cur]],right[cur]);
    for(int i=left[cur];i<=right[cur];i++){
        if (vis[i]) continue;
        dfs2(i);
        ansl[c[cur]]=mini(ansl[c[cur]],ansl[c[i]]);
        ansr[c[cur]]=maxi(ansr[c[cur]],ansr[c[i]]);
    }
}
int main(){
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        scanf("%d%d", a+i, r+i);
    }
    for(int i=0;i<n;i++) ord[i]=i;
    sort(ord,ord+n,cmp);
    for(int i=0;i<n;i++){
        ap[i]=a[ord[i]];
        rp[i]=r[ord[i]];
        rev[ord[i]]=i;
    }
    for(int i=0;i<n;i++){
        left[i]=leftBinSearch(ap[i]-rp[i],i);
        right[i]=rightBinSearch(ap[i]+rp[i],i);
    }
    memset(pos,-1,sizeof(pos));
    for(int i=0;i<n;i++){
        if (pos[i]==-1) dfs(i);
    }
    for(int i=1;i<=comp;i++){
        ansl[i]=n;
        ansr[i]=0;
    }
    for(int i=0;i<n;i++){
        if (!vis[i]) dfs2(i);
    }
    printf("%d", ansr[c[rev[0]]]-ansl[c[rev[0]]]+1);
    for(int i=1;i<n;i++){
        printf(" %d", ansr[c[rev[i]]]-ansl[c[rev[i]]]+1);
    }puts("");
    return 0;
}
