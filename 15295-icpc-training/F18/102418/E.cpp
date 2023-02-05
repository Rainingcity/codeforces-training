#include<cstdio>
#include<cstring>
using namespace std;
int maxi(int x,int y){return x>y?x:y;}
int n;
int p[200100];
int val[200100];
int mx[200100];
int cnt[200100];
int main(){
    scanf("%d", &n);
    memset(mx,-1,sizeof(mx));
    memset(cnt,0,sizeof(cnt));
    for(int i=1;i<=n;i++){
        scanf("%d%d", val+i, p+i);
    }
    for(int i=n;i>0;i--){
        if (val[i]>mx[i]){
            cnt[i]++;
            mx[i]=val[i];
        }
        mx[p[i]]=maxi(mx[p[i]],mx[i]);
        cnt[p[i]]+=cnt[i];
    }printf("%d\n", cnt[1]);
    return 0;
}
