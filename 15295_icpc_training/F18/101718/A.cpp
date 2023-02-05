#include<cstdio>
#include<vector>
using namespace std;
int n;
int cnt[100100];
vector<int> v[100100];
void dfs(int cur,int prev){
    cnt[cur]=1;
    int vsize=v[cur].size();
    for(int i=0;i<vsize;i++){
        if (v[cur][i]==prev) continue;
        dfs(v[cur][i],cur);
        cnt[cur]+=cnt[v[cur][i]];
    }
    return;
}
int main(){
    scanf("%d", &n);
    if (n&1){
        puts("-1");
        return 0;
    }
    for(int i=1;i<n;i++){
        int x,y;scanf("%d%d", &x, &y);x--;y--;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    dfs(0,-1);
    int ans=0;
    for(int i=1;i<n;i++){
        if (!(cnt[i]&1)) ans++;
    }printf("%d\n", ans);
    return 0;
}
