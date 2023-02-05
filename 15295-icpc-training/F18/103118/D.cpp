#include<cstdio>
#include<vector>
using namespace std;
int n,m;
int par[200200];
struct Edge{
    int x,y;
    Edge(){}
    Edge(int _x,int _y){
        x=_x;y=_y;
    }
}curEdge[400200],e[400200],pendingEdge[400200],conS[200200],conT[200200];
int nCurEdge,nPendingEdge;
int getRoot(int x){
    if (x==par[x]) return x;
    return (par[x]=getRoot(par[x]));
}
bool uni(int x,int y){
    int rx=getRoot(x),ry=getRoot(y);
    if (rx!=ry){
        par[rx]=ry;
        return true;
    }else return false;
}
int S,T,degS,degT,numS,numT;
bool fS[200200],fT[200200];
vector<int> comp;
int main(){
    scanf("%d%d", &n, &m);
    for(int i=0;i<n;i++) par[i]=i;
    for(int i=0;i<m;i++){
        int x,y;scanf("%d%d", &x, &y);x--;y--;
        e[i]=Edge(x,y);
    }
    scanf("%d%d%d%d", &S, &T, &degS, &degT);S--;T--;
    for(int i=0;i<m;i++){
        if (e[i].x==S || e[i].y==S || e[i].x==T || e[i].y==T){
            pendingEdge[nPendingEdge++]=e[i];
            continue;
        }
        bool F=uni(e[i].x,e[i].y);
        if (F){
            curEdge[nCurEdge++]=e[i];
        }
    }
    for(int i=0;i<n;i++) par[i]=getRoot(i);
    for(int i=0;i<n;i++){
        if (i==S || i==T) continue;
        if (par[i]==i){
            comp.push_back(i);
        }
    }
    bool isConnected=false;
    for(int i=0;i<nPendingEdge;i++){
        int x=pendingEdge[i].x,y=pendingEdge[i].y;
        if (x==S && y==T || x==T && y==S){
            isConnected=true;
            continue;
        }
        if (par[x]==par[y]) continue;
        if (x==S){
            fS[par[y]]=true;
            conS[par[y]]=pendingEdge[i];
        }else if (y==S){
            fS[par[x]]=true;
            conS[par[x]]=pendingEdge[i];
        }else if (x==T){
            fT[par[y]]=true;
            conT[par[y]]=pendingEdge[i];
        }else if (y==T){
            fT[par[x]]=true;
            conT[par[x]]=pendingEdge[i];
        }
    }
    int nComp=comp.size(),k=0;
    for(int i=0;i<nComp;i++){
        if (fS[comp[i]] && fT[comp[i]]){
            k++;
        }else if (fS[comp[i]]){
            numS++;
            curEdge[nCurEdge++]=conS[comp[i]];
        }else if (fT[comp[i]]){
            numT++;
            curEdge[nCurEdge++]=conT[comp[i]];
        }else{
            puts("No");
            return 0;
        }
    }
    if (numS>degS || numT>degT){
        puts("No");
        return 0;
    }
    if (k>0 && k+1+numS+numT>degS+degT){
        puts("No");
        return 0;
    }
    bool first=true;
    for(int i=0;i<nComp && (numS<degS || numT<degT) && numS<=degS && numT<=degT;i++){
        if (fS[comp[i]] && fT[comp[i]]){
            if (first){
                first=false;
                numS++;numT++;
                curEdge[nCurEdge++]=conS[comp[i]];
                curEdge[nCurEdge++]=conT[comp[i]];
            }else if (numS<degS){
                numS++;
                curEdge[nCurEdge++]=conS[comp[i]];
            }else{
                numT++;
                curEdge[nCurEdge++]=conT[comp[i]];
            }
        }
    }
    if (k==0 && isConnected){
        if (numS==degS || numT==degT){
            puts("No");
            return 0;
        }
        curEdge[nCurEdge++]=Edge(S,T);
    }
    if (nCurEdge!=n-1 || numS>degS || numT>degT){
        puts("No");
        return 0;
    }else{
        puts("Yes");
        for(int i=0;i<nCurEdge;i++){
            printf("%d %d\n", curEdge[i].x+1, curEdge[i].y+1);
        }
    }
    return 0;
}
