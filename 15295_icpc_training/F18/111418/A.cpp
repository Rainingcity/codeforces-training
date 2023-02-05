#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
const double pi=3.141592653;
const double eps=1e-7;
int n;
struct point{
    double x,y,c;
    point(){}
    point(double _x,double _y){
        x=_x;y=_y;
        if (x>0){
            if (y>=0) c=1;
            else c=4;
        }else{
            if (y>=0) c=2;
            else c=3;
        }
    }
    double length(){
        return sqrt(x*x+y*y);
    }
}a[100100];
bool cmp(point x,point y){
    if (x.c!=y.c) return x.c<y.c;
    return x.x*y.y>x.y*y.x;
}
int cross(point x,point y){
    return x.x*y.y-x.y*y.x;
}
int dot(point x,point y){
    return x.x*y.x+x.y*y.y;
}
point calcAng(point x,point y){
    double angsin=cross(x,y)/x.length()/y.length();
    double angcos=dot(x,y)/x.length()/y.length();
    return point(angcos,angsin);
}
int main(){
    scanf("%d", &n);
    if (n==1){
        puts("0.000000");
        return 0;
    }
    for(int i=0;i<n;i++){
        int x,y;scanf("%d%d", &x, &y);
        a[i]=point(x,y);
    }
    sort(a,a+n,cmp);
    point ans=calcAng(a[n-1],a[0]);
    bool F=0;
    if (ans.x==1 && ans.y==0) F=1;
    for(int i=1;i<n;i++){
        point res=calcAng(a[i-1],a[i]);
        if (res.x==1 && res.y==0) continue;
        if (F || cmp(ans,res)){
            ans=res;
            F=0;
        }
    }
    if (F){
        puts("0.000000");
        return 0;
    }
    double ang=0.0;
    if (ans.x+eps<=0){
        ang=pi-asin(ans.y);
    }else{
        if (ans.y+eps<=0) ang=asin(ans.y)+2*pi;
        else ang=asin(ans.y);
    }
    printf("%lf\n", 360-ang/pi*180);
    return 0;
}
