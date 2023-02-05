#include<cstdio>
using namespace std;
int n;
int a[2020],b[2020];
int f[11][2020][11][11][11];
int absi(int x){
    return x<0?-x:x;
}
int mini(int x,int y){
    return x<y?x:y;
}
int dp(int flr, int cur, int p1, int p2, int p3){
    if (f[flr][cur][p1][p2][p3]!=0) return f[flr][cur][p1][p2][p3];
    f[flr][cur][p1][p2][p3]=50000;
    if (cur==n){
        if (p1==0 && p2==0 && p3==0) f[flr][cur][p1][p2][p3]=0;
        if (p1!=0) f[flr][cur][p1][p2][p3]=mini(f[flr][cur][p1][p2][p3],dp(p1,cur,0,p2,p3)+absi(flr-p1)+1);
        if (p2!=0) f[flr][cur][p1][p2][p3]=mini(f[flr][cur][p1][p2][p3],dp(p2,cur,p1,0,p3)+absi(flr-p2)+1);
        if (p3!=0) f[flr][cur][p1][p2][p3]=mini(f[flr][cur][p1][p2][p3],dp(p3,cur,p1,p2,0)+absi(flr-p3)+1);
        return f[flr][cur][p1][p2][p3];
    }

    if (p1!=0) f[flr][cur][p1][p2][p3]=mini(f[flr][cur][p1][p2][p3],dp(p1,cur,0,p2,p3)+absi(flr-p1)+1);
    if (p2!=0) f[flr][cur][p1][p2][p3]=mini(f[flr][cur][p1][p2][p3],dp(p2,cur,p1,0,p3)+absi(flr-p2)+1);
    if (p3!=0) f[flr][cur][p1][p2][p3]=mini(f[flr][cur][p1][p2][p3],dp(p3,cur,p1,p2,0)+absi(flr-p3)+1);

    if (p1==0) f[flr][cur][p1][p2][p3]=mini(f[flr][cur][p1][p2][p3],dp(a[cur],cur+1,b[cur],p2,p3)+absi(flr-a[cur])+1);
    else if (p2==0) f[flr][cur][p1][p2][p3]=mini(f[flr][cur][p1][p2][p3],dp(a[cur],cur+1,p1,b[cur],p3)+absi(flr-a[cur])+1);
    else if (p3==0) f[flr][cur][p1][p2][p3]=mini(f[flr][cur][p1][p2][p3],dp(a[cur],cur+1,p1,p2,b[cur])+absi(flr-a[cur])+1);
    else{
        f[flr][cur][p1][p2][p3]=mini(f[flr][cur][p1][p2][p3],dp(b[cur],cur+1,p1,p2,p3)+absi(flr-a[cur])+absi(a[cur]-b[cur])+2);
        f[flr][cur][p1][p2][p3]=mini(f[flr][cur][p1][p2][p3],dp(p1,cur+1,b[cur],p2,p3)+absi(flr-a[cur])+absi(a[cur]-p1)+2);
        f[flr][cur][p1][p2][p3]=mini(f[flr][cur][p1][p2][p3],dp(p2,cur+1,p1,b[cur],p3)+absi(flr-a[cur])+absi(a[cur]-p2)+2);
        f[flr][cur][p1][p2][p3]=mini(f[flr][cur][p1][p2][p3],dp(p3,cur+1,p1,p2,b[cur])+absi(flr-a[cur])+absi(a[cur]-p3)+2);
    }return f[flr][cur][p1][p2][p3];
}
int main(){
    scanf("%d", &n);
    for(int i=0;i<n;i++) scanf("%d%d", a+i, b+i);
    printf("%d\n", dp(1,0,0,0,0));
    return 0;
}
