#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int n,m,k;
vector<int> v[3010];
struct forb{
    int a,b,c;
    forb(){}
    forb(int _a,int _b,int _c){
        a=_a;b=_b;c=_c;
    }
}f[100100];
int qfront=0,qtail=0,qcur[10001000],qprev[10001000];
bool isEqual(forb x, forb y){
    return x.a==y.a && x.b==y.b && x.c==y.c;
}
bool cmp(forb x, forb y){
    return (x.a!=y.a?x.a<y.a:(x.b!=y.b?x.b<y.b:x.c<y.c));
}
int find(forb tar){
    int l=0,r=k-1;
    while (l<=r){
        int mid=(l+r)>>1;
        if (isEqual(f[mid],tar)) return mid;
        if (cmp(f[mid],tar)) l=mid+1;
        else r=mid-1;
    }return -1;
}
void PRINT(int cur,int num){
    if (cur==-1){
        printf("%d\n1 ", num);
        return;
    }
    PRINT(qprev[cur],num+1);
    printf("%d ", qcur[cur]+1);
}
bool CheckQ[3010][3010];
int main(){
    scanf("%d%d%d", &n, &m, &k);
    for(int i=0;i<m;i++){
        int x,y;
        scanf("%d%d", &x, &y);x--;y--;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    for(int i=0;i<k;i++){
        int x,y,z;
        scanf("%d%d%d", &x, &y, &z);x--;y--;z--;
        f[i]=forb(x,y,z);
    }
    sort(f, f+k, cmp);
    for(int i=0;i<v[0].size();i++){
        if (v[0][i]==n-1){
            printf("1\n1 %d\n", n);
            return 0;
        }
        qcur[qtail]=v[0][i];
        qprev[qtail++]=-1;
        CheckQ[0][v[0][i]]=true;
    }
    while(qfront<qtail){
        int pre=(qprev[qfront]==-1?0:qcur[qprev[qfront]]);
        int cur=qcur[qfront];
        for(int i=0;i<v[cur].size();i++){
            int nx=v[cur][i];
            if (CheckQ[cur][nx]) continue;
            int kk=find(forb(pre,cur,nx));
            if (kk==-1){
                if (nx==n-1){
                    PRINT(qfront, 1);
                    printf("%d\n", n);
                    return 0;
                }
                qcur[qtail]=nx;
                qprev[qtail++]=qfront;
                CheckQ[cur][nx]=true;
            }
        }
        qfront++;
    }puts("-1");
    return 0;
}
