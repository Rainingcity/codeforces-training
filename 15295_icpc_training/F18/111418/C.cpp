#include<cstdio>
#include<algorithm>
using namespace std;
double absi(double x){return x<0?-x:x;}
int n,q;
struct Vector{
    double x,y;
    Vector(){}
    Vector(double _x, double _y){
        x=_x;y=_y;
    }
    bool operator< (Vector b){
        return (x!=b.x?x<b.x:y<b.y);
    }
    bool operator== (Vector b){
        return x==b.x && y==b.y;
    }
    bool operator> (Vector b){
        return (x!=b.x?x>b.x:y>b.y);
    }
    Vector operator+ (Vector b){
        return Vector(x+b.x,y+b.y);
    }
    Vector operator- (Vector b){
        return Vector(x-b.x,y-b.y);
    }
}va[100100],vb[20100];
double A,B,Cm;
double calc(Vector x){
    return A*x.x+B*x.y;
}
bool cmp(Vector x, Vector y){
    return calc(x)<calc(y);
}
double intersectx(double A1,double B1,double C1,double A2,double B2,double C2){
    return (C2*B1-C1*B2)/(A1*B2-A2*B1);
}
double intersecty(double A1,double B1,double C1,double A2,double B2,double C2){
	return (C2*A1-C1*A2)/(A1*B2-A2*B1);
}
int main(){
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        int x,y;scanf("%d%d", &x, &y);
        va[i]=Vector(x,y);
    }
    A=va[1].y-va[0].y;
    B=va[0].x-va[1].x;
    Cm=A*va[1].x+B*va[1].y;
    scanf("%d", &q);
    for(int i=0;i<q;i++){
        int x,y;scanf("%d%d", &x, &y);
        vb[i]=Vector(x,y);
    }
    sort(vb,vb+q,cmp);
    va[n]=va[0];
    int l=2,r=n-1;
    for(int i=0;i<q;i++){
        if (calc(vb[i])<=Cm){
            puts("NO");
            return 0;
        }
        while(l<r && calc(va[l])<calc(vb[i])) l++;
        while(r>l && calc(va[r])<calc(vb[i])) r--;
        if (l+1==r && calc(va[l])==calc(vb[i]) && calc(va[r])==calc(vb[i])){
        	puts("NO");
        	return 0;
        }
        double int1x=intersectx(A,B,-(calc(vb[i])),va[l].y-va[l-1].y,va[l-1].x-va[l].x,va[l-1].y*va[l].x-va[l-1].x*va[l].y);
        double int2x=intersectx(A,B,-(calc(vb[i])),va[r].y-va[r+1].y,va[r+1].x-va[r].x,va[r+1].y*va[r].x-va[r+1].x*va[r].y);
        double int1y=intersecty(A,B,-(calc(vb[i])),va[l].y-va[l-1].y,va[l-1].x-va[l].x,va[l-1].y*va[l].x-va[l-1].x*va[l].y);
        double int2y=intersecty(A,B,-(calc(vb[i])),va[r].y-va[r+1].y,va[r+1].x-va[r].x,va[r+1].y*va[r].x-va[r+1].x*va[r].y);
        if ((int1x-vb[i].x)*(vb[i].x-int2x)<=0 && (int1y-vb[i].y)*(vb[i].y-int2y)<=0){
            puts("NO");
            return 0;
        }
    }
    puts("YES");
}
