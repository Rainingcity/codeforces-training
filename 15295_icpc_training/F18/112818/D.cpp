#include<cstdio>
#include<algorithm>
using namespace std;
int n,A,B;
int seppos[100100],sepn;
bool stspot;
struct Cow{
    bool spot;
    int x;
    Cow(){}
    Cow(bool _spot,int _x){
        spot=_spot;
        x=_x;
    }
    Cow(char op[3],int _x){
        if (op[0]=='S') spot=true;
        else spot=false;
        x=_x;
    }
}a[100100];
bool operator< (Cow x, Cow y){
    return x.x<y.x;
}
int binSearch(int tar){
    if (tar<=seppos[0]){
        return 0;
    }else if (tar>seppos[sepn-1]){
        return sepn;
    }
    int l=0,r=sepn-1;
    while(l<r){
        int mid=(l+r)>>1;
        if (seppos[mid]==tar) return mid;
        if (seppos[mid]<tar) l=mid+1;
        else r=mid;
    }
    return l;
}
int main(){
    scanf("%d%d%d", &n, &A, &B);
    for(int i=0;i<n;i++){
        char op[3];int x;
        scanf("%s%d", op, &x);
        a[i]=Cow(op,x);
    }
    sort(a,a+n);
    sepn=0;
    stspot=a[0].spot;
    for(int i=0;i<n-1;i++){
        if (a[i].spot==a[i+1].spot) continue;
        if (a[i].spot){
            seppos[sepn++]=(a[i].x+a[i+1].x)>>1;
        }else{
            seppos[sepn++]=(a[i].x+a[i+1].x-1)>>1;
        }
    }
    int posA=binSearch(A),posB=binSearch(B);
    if (posA==posB){
        if ((posA&1)^stspot){
            printf("%d\n", B-A+1);
        }else{
            puts("0");
        }
    }else{
        int ans=0;
        bool cur=stspot^(posA&1);
        if (cur) ans+=seppos[posA]-A+1;
        for (int i=posA+1;i<posB;i++){
            cur^=1;
            if (cur){
                ans+=seppos[i]-seppos[i-1];
            }
        }
        if ((posB&1)^stspot){
        	ans+=B-seppos[posB-1];
        }
        printf("%d\n", ans);
    }
}
