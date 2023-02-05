#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;
int n;
int a[4000];
vector<int> v[400];
int itv[400];
int par[400];
int ans[400];
int getRoot(int x){
    if (x==par[x]) return x;
    return (par[x]=getRoot(par[x]));
}
void uni(int x,int y){
    int rx=getRoot(x),ry=getRoot(y);
    if (rx!=ry){
        if (rx<ry) par[ry]=rx;
        else par[rx]=ry;
    }
}
int main(){
    scanf("%d", &n);
    for(int i=0;i<n;i++) scanf("%d", a+i);
    for(int i=0;i<n;i++) par[i]=i;
    for(int i=0;i<n;i++){
        char x[400];
        scanf("%s", x);
        for(int j=i+1;j<n;j++){
            if (x[j]=='1'){
                uni(i,j);
            }
        }
    }
    for(int i=0;i<n;i++) par[i]=getRoot(i);
    for(int i=0;i<n;i++) v[par[i]].push_back(a[i]);
    for(int i=0;i<n;i++) sort(v[i].begin(),v[i].end());
    for(int i=0;i<n;i++){
        int t=par[i];
        ans[i]=v[t][itv[t]++];
    }
    printf("%d", ans[0]);
    for(int i=1;i<n;i++) printf(" %d", ans[i]);
    puts("");
    return 0;
}
