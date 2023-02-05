#include<cstdio>
using namespace std;
typedef long long ll;
int n;
ll a[510][510];
ll f[510][510];
int ord[510];
ll ans[510];
ll mini(ll x,ll y){
    return x<y?x:y;
}
int main(){
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%I64d", a[i]+j);
        }
    }
    for(int i=n-1;i>=0;i--){
        scanf("%d", ord+i);
        ord[i]--;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            f[i][j]=a[ord[i]][ord[j]];
        }
    }
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                f[i][j]=mini(f[i][j], f[i][k]+f[k][j]);
            }
        }
        ans[k]=0;
        for(int i=0;i<=k;i++){
            for(int j=0;j<=k;j++){
                ans[k]+=f[i][j];
            }
        }
    }
    for(int i=n-1;i>0;i--) printf("%I64d ", ans[i]);
    printf("%I64d\n", ans[0]);
    return 0;
}
