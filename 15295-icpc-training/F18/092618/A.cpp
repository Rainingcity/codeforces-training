#include<cstdio>
#include<queue>
#include<algorithm>
#include<cmath>
using namespace std;
const long double eps=1e-15;
int n,m,tarx,tary;
int a[110],b[110],r[110];
long double dist[110];
bool vis[110];
vector<int> v[110];
priority_queue<pair<long double, int> > q;
long double maxi(long double x,long double y){
    return x>y?x:y;
}
long double calc(int i,int j){
    return maxi(sqrt((a[i]-a[j])*(a[i]-a[j])+(b[i]-b[j])*(b[i]-b[j]))-r[i]-r[j],0);
}
long double calctar(int i){
    return maxi(sqrt((a[i]-tarx)*(a[i]-tarx)+(b[i]-tary)*(b[i]-tary))-r[i],0);
}
int main(){
    scanf("%d%d%d%d", &n, &m, &tarx, &tary);
    for(int i=1;i<=n;i++) scanf("%d%d%d", a+i, b+i, r+i);
    a[0]=0;b[0]=0;r[0]=0;
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            if (i==j) continue;
            if ((a[i]-a[j])*(a[i]-a[j])+(b[i]-b[j])*(b[i]-b[j])<=(r[i]+r[j]+m)*(r[i]+r[j]+m)){
                v[i].push_back(j);
                v[j].push_back(i);
            }
        }
    }
    //    puts("Pass");
    q.push(make_pair((long double)(0.0),0));vis[0]=true;
    while(!q.empty()){
        pair<long double,int> curq=q.top();
        q.pop();
        int cur=curq.second;
        long double cdist=curq.first;
        if (cdist>dist[cur]) continue;
        for(int i=0;i<v[cur].size();i++){
            int j=v[cur][i];
            if (j==0) continue;
            long double d=cdist+calc(cur,j);
            if (!vis[j] || d<dist[j]){
                q.push(make_pair(d,j));
                dist[j]=d;vis[j]=true;
            }
        }
    }
    //    puts("Pass");
    long double ans=100000.000;
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            long double tt=calctar(i)+calctar(j);
            if (tt>m) continue;
            if (!vis[i] || !vis[j]) continue;
            if (ans>tt+dist[i]+dist[j]) ans=tt+dist[i]+dist[j];
        }
    }
    if (ans==100000.000) puts("-1");
    else printf("%lf\n", (double)ans);
    return 0;
}
