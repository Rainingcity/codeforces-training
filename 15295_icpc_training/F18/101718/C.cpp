#include<cstdio>
#include<vector>
using namespace std;
int n,k;
vector<int> v[1000100];
int ans[1000100];
int ans2[1000100];
int dfs(int cur){
    int vsize=v[cur].size();
    if (vsize==0){
        ans[cur]=1;
        ans2[cur]=1;
        return 0;
    }
    int ret=1000100;
    ans[cur]=0;
    int updateans=0;
    for(int i=0;i<vsize;i++){
        int t=dfs(v[cur][i]);
        if (t<k){
            ans[cur]+=ans2[v[cur][i]];
            ans2[cur]+=ans2[v[cur][i]];
            if (updateans<ans[v[cur][i]]-ans2[v[cur][i]]) updateans=ans[v[cur][i]]-ans2[v[cur][i]];
        }
        else{
            if (updateans<ans[v[cur][i]]) updateans=ans[v[cur][i]];
        }
        if (ret>t+1) ret=t+1;
    }
    ans[cur]+=updateans;
    return ret;
}
int main(){
    scanf("%d%d", &n, &k);
    for(int i=1;i<n;i++){
        int x;scanf("%d", &x);x--;
        v[x].push_back(i);
    }
    dfs(0);
    printf("%d\n", ans[0]);
    return 0;
}
