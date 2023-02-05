#include<cstdio>
#include<vector>
#include<queue>
using namespace std;
int n,m,s,t;
vector<int> v[1010];
int l[1010];
int lr[1010];
queue<int> q;
int absi(int x){
    return x<0?-x:x;
}
int main(){
    scanf("%d%d%d%d", &n, &m, &s, &t);s--;t--;
    for(int i=0;i<m;i++){
        int x,y;
        scanf("%d%d", &x, &y);x--;y--;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    l[s]=0;
    q.push(s);
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        for(int i=0;i<v[cur].size();i++){
            int tt=v[cur][i];
            if (tt==s) continue;
            if (l[tt]) continue;
            l[tt]=l[cur]+1;
            q.push(tt);
        }
    }
    lr[t]=0;
    q.push(t);
    while(!q.empty()){
        int cur=q.front();
        q.pop();
        for(int i=0;i<v[cur].size();i++){
            int tt=v[cur][i];
            if (tt==t) continue;
            if (lr[tt]) continue;
            lr[tt]=lr[cur]+1;
            q.push(tt);
        }
    }
    int ans=0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if (l[t]<=l[i]+lr[j]+1 && l[t]<=l[j]+lr[i]+1) ans++;
        }
    }printf("%d\n", ans-m);
    return 0;
}
