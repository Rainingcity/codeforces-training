#include<cstdio>
using namespace std;
typedef long long ll;
int n;
struct line{
    int x1,x2,y1,y2;
    line(){}
    line(int _x1,int _y1,int _x2,int _y2){
        x1=_x1;y1=_y1;x2=_x2;y2=_y2;
    }
}a[1010];
int sig(ll x){
    return x<0?-1:(x>0?1:0);
}
ll cross(int x1,int y1,int x2,int y2){
    return (ll)(x1)*y2-(ll)(x2)*y1;
}
bool checkSamePoint(line l1,line l2){
    if (l1.x1==l2.x1 && l1.y1==l2.y1) return true;
    if (l1.x2==l2.x2 && l1.y2==l2.y2) return true;
    if (l1.x1==l2.x2 && l1.y1==l2.y2) return true;
    if (l1.x2==l2.x1 && l1.y2==l2.y1) return true;
    return false;
}
bool inters(line l1,line l2){
    if (checkSamePoint(l1,l2)) return true;
    bool F=1;
    int v1x=l2.x1-l1.x1,v1y=l2.y1-l1.y1;
    int v2x=l2.x2-l1.x1,v2y=l2.y2-l1.y1;
    int v0x=l1.x2-l1.x1,v0y=l1.y2-l1.y1;
    int c1=sig(cross(v1x,v1y,v0x,v0y)),c2=sig(cross(v2x,v2y,v0x,v0y));
    if (!(c1==0 && c2==0)) F=0;
    if (c1*c2>0) return false;
    v1x=l2.x1-l1.x2,v1y=l2.y1-l1.y2;
    v2x=l2.x2-l1.x2,v2y=l2.y2-l1.y2;
    v0x=l1.x1-l1.x2,v0y=l1.y1-l1.y2;
    c1=sig(cross(v1x,v1y,v0x,v0y)),c2=sig(cross(v2x,v2y,v0x,v0y));
    if (!(c1==0 && c2==0)) F=0;
    if (c1*c2>0) return false;
    if (F) return false;
    return true;
}
int counte[1010];
int main(){
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        int p,q,r,s;scanf("%d%d%d%d", &p, &q, &r, &s);
        a[i]=line(p,q,r,s);
    }
    int countv=0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if (inters(a[i],a[j])){
                countv++;
                counte[i]++;
                counte[j]++;
            }
        }
    }
    int ans=1;
    for(int i=0;i<n;i++) if (counte[i]) ans+=counte[i]-1;
    if (countv==0 && ans==1) puts("0");
    else printf("%d\n", ans-countv);
    return 0;
}
