#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
int mini(int x,int y){return x>y?y:x;}
int B,E,P;
int n,m;
vector<int> v[40010];
int dis[5][40010],disn;
queue<int> q;
bool vis[40010];
void bfs(int st){
    memset(vis,false,sizeof(vis));
    q.push(st);vis[st]=true;dis[disn][st]=0;
    while(!q.empty()){
        int t=q.front();q.pop();
        int sz=v[t].size();
        for(int i=0;i<sz;i++){
            int j=v[t][i];
            if (!vis[j]){
                dis[disn][j]=dis[disn][t]+1;
                q.push(j);vis[j]=true;
            }
        }
    }
    disn++;
}

int main(){
    scanf("%d%d%d%d%d", &B, &E, &P, &n, &m);
    for(int i=0;i<m;i++){
        int x,y;scanf("%d%d", &x, &y);x--;y--;
        v[x].push_back(y);v[y].push_back(x);
    }
    memset(dis,-1,sizeof(dis));
    bfs(0);bfs(1);bfs(n-1);
    long long ans=(long long)B*dis[0][n-1]+(long long)E*dis[1][n-1];
    for(int i=0;i<n;i++){
        if (dis[0][i]==-1 || dis[1][i]==-1 || dis[2][i]==-1) continue;
        ans=mini(ans,(long long)B*dis[0][i]+(long long)E*dis[1][i]+(long long)P*dis[2][i]);
    }
    printf("%lld\n", ans);
    return 0;
}
