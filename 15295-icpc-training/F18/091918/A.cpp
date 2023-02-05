#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
using namespace std;
int maxi(int x,int y){return x<y?y:x;}
int mini(int x,int y){return x<y?x:y;}
int n,m,c,k;
struct agent{
    int x,y,r;
    agent(){}
    agent(int _x,int _y,int _r){
        x=_x;y=_y;r=_r;
    }
}a[1010];
const agent zero=agent(0,0,0);
struct state{
    int pos,num;
    state(){}
    state(int _pos, int _num){
        pos=_pos;num=_num;
    }
}st[2020];
bool cmp(state x, state y){
    return x.pos<y.pos;
}
int main(){
    int testCase;scanf("%d", &testCase);
    while(testCase--){
        int ANS=0;
        scanf("%d%d%d%d", &n, &m, &c, &k);
        for(int i=0;i<c;i++){
            int x,y,r;scanf("%d%d%d", &x, &y, &r);
            a[i]=agent(x,y,r);
        }
        for(int i=1;i<=n;i++){
            int t=0;
            for(int j=0;j<c;j++){
                double d=a[j].x-i;
                d=(double)(a[j].r)*a[j].r-d*d;
                if (d<0) continue;
                int dd=(int)sqrt(d);
                st[t++]=state(maxi(a[j].y-dd,1),1);
                st[t++]=state(mini(a[j].y+dd,m)+1,-1);
            }
            sort(st,st+t,cmp);
            int curPos=1, curNum=0,j=0;
            while(j<t){
                if (curNum>=k){
                    ANS+=st[j].pos-curPos;
                }curPos=st[j].pos;
                while(j<t && st[j].pos==curPos) curNum+=st[j++].num;
            }
        }printf("%d\n", ANS);
        for(int i=0;i<c;i++) a[i]=zero;
    }
}
