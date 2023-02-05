#include<cstdio>
using namespace std;
int n;
int par[1010];
struct Edge{
    int x,y;
    Edge(){}
    Edge(int _x,int _y){
        x=_x;y=_y;
    }
}delEdge[1010];
int rootCity[1010],nRootCity,nDelEdge;
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
int main(){
    scanf("%d", &n);
    for(int i=0;i<n;i++) par[i]=i;
    for(int i=1;i<n;i++){
        int x,y;scanf("%d%d", &x, &y);x--;y--;
        bool F=uni(x,y);
        if (!F){
            delEdge[nDelEdge++]=Edge(x,y);
        }
    }
    for(int i=0;i<n;i++) par[i]=getRoot(i);
    for(int i=0;i<n;i++){
        if (par[i]==i) rootCity[nRootCity++]=i;
    }
    printf("%d\n", nDelEdge);
    for(int i=0;i<nDelEdge;i++){
        printf("%d %d %d %d\n", delEdge[i].x+1, delEdge[i].y+1, rootCity[i]+1, rootCity[i+1]+1);
    }
    return 0;
}
