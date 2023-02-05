#include<cstdio>
#include<vector>
using namespace std;
typedef long long ll;
int n,m;
bool f[100100];
int a[100100];
vector<int> v[100100];
int dfs(int cur){
    f[cur]=1;
    int vsize=v[cur].size();
    int ret=a[cur];
    for(int i=0;i<vsize;i++){
        if (f[v[cur][i]]) continue;
        int k=dfs(v[cur][i]);
        if (ret>k) ret=k;
    }
    return ret;
}
int main(){
    scanf("%d%d", &n, &m);
    for(int i=0;i<n;i++){
        scanf("%d", a+i);
    }
    for(int i=0;i<m;i++){
        int x,y;scanf("%d%d", &x, &y);x--;y--;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    ll ans=0;
    for(int i=0;i<n;i++){
        if (!f[i]) ans=ans+dfs(i);
    }
    printf("%I64d\n", ans);
    return 0;
}
