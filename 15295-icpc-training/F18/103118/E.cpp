#include<cstdio>
#include<vector>
using namespace std;
typedef pair<int,int> pii;
int maxi(int x,int y){return x<y?y:x;}
int n,q;
int pos[200200],hei[200200],par[200200],dis[200200],pre[200200],fat[200200][20];
int head[200200],nHead;
int v[200200],vn;
int binSearch(int tar,int st){
    int le=st,ri=n-1;
    while(le<ri){
        int mid=(le+ri+1)>>1;
        if (pos[mid]==tar) return mid;
        if (pos[mid]<tar) le=mid;
        else ri=mid-1;
    }return le;
}
int main(){
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        scanf("%d%d", pos+i, hei+i);
    }
    v[0]=n-1;vn=1;
    head[nHead++]=n-1;
    par[n-1]=n-1;
    dis[n-1]=pos[n-1]+hei[n-1];
    for(int i=n-2;i>=0;i--){
        int t=binSearch(pos[i]+hei[i],i);
        if (i==t){
            par[i]=i;
            dis[i]=pos[i]+hei[i];
            head[nHead++]=i;
        }else{
            while(vn>0 && v[--vn]<=t);
            if (v[vn]>t) vn++;
            int tpre=v[vn];
            par[i]=par[tpre];
            dis[i]=maxi(dis[tpre],pos[i]+hei[i]);
        }
        v[vn++]=i;
    }
    pre[n-1]=0;
    fat[n-1][0]=n-1;
    for(int i=1;i<nHead;i++){
        int curHead=head[i];
        fat[curHead][0]=par[curHead+1];
    }
    for(int i=n-2;i>=0;i--){
        pre[i]=pre[par[i]+1]+pos[par[i]+1]-dis[i];
    }
    int fatSz=0;
    for(int k=1;k<20;k++){
        bool F=false;
        for(int i=0;i<nHead;i++){
            int curHead=head[i];
            fat[curHead][k]=fat[fat[curHead][k-1]][k-1];
            if (fat[curHead][k]!=n-1) F=true;
        }
        if (!F){
            fatSz=k+1;
            break;
        }
    }
    scanf("%d", &q);
    for(int i=0;i<q;i++){
        int x,y;scanf("%d%d", &x, &y);x--;y--;
        int x1=par[x];
        if (x1>=y){
            puts("0");
            continue;
        }
        int it=0;
        while(it<fatSz && fat[x1][it]<y) it++;
        it--;
        while(it>=0){
            x1=fat[x1][it];
            while(it>=0 && fat[x1][it]>=y) it--;
        }
        printf("%d\n", pre[x]-pre[x1+1]);
    }return 0;
}
