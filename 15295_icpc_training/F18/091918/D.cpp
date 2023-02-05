#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int l,r,n,m;
vector<int> v[5010];
bool F[5010];
bool ansl[5010];
bool ansr[5010];
bool ansrr[5010];
void dfs(int cur){
    if (cur==l){
        for(int i=0;i<n;i++) ansl[i]&=F[i];
    }
    if (cur==r){
        for(int i=0;i<n;i++){
            ansr[i]&=F[i];
            ansrr[i]&=!F[i];
        }return;
    }
    for(int i=0;i<n;i++){
        if (F[i]) continue;
        bool checkk=true;
        for(int j=0;j<v[i].size() && checkk;j++) checkk&=F[v[i][j]];
        if (checkk){
            F[i]=true;
            dfs(cur+1);
            F[i]=false;
        }
    }
}
int main(){
    scanf("%d%d%d%d", &l, &r, &n, &m);
    for(int i=0;i<m;i++){
        int x,y;scanf("%d%d", &x, &y);
        v[y].push_back(x);
    }
    for(int i=0;i<n;i++) ansl[i]=ansr[i]=ansrr[i]=true;
    dfs(0);
    int ansL=0,ansR=0,ansRR=0;
    for(int i=0;i<n;i++){
        if (ansl[i]) ansL++;
        if (ansr[i]) ansR++;
        if (ansrr[i]) ansRR++;
    }
    printf("%d\n%d\n%d\n", ansL, ansR, ansRR);
    return 0;
}
