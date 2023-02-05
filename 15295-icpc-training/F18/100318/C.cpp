#include<cstdio>
using namespace std;
typedef long long ll;
ll ans=0;
int n,L;
ll a[50];
ll mini(ll x, ll y){
    return x<y?x:y;
}
int main(){
    scanf("%d%d", &n, &L);
    for(int i=0;i<n;i++){
        int x;scanf("%d", &x);
        a[i]=x;
    }
    int cur=0,mul=1;
    ans=a[0]*L;
    for(int i=1;i<n;i++){
        mul<<=1;
        if ((a[cur]<<(i-cur))>=a[i]){
            int t=L/mul,r=L%mul;
            if (r==0){
                ans=a[i]*t;
            }else{
                ans=mini(a[i],ans-(a[cur]<<(i-cur))*t)+a[i]*t;
            }cur=i;
        }
    }
    printf("%lld\n", ans);
    return 0;
}
