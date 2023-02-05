#include<cstdio>
using namespace std;
typedef long long ll;
ll n,p,r;
ll fastpow(ll x,ll y){
    if (y==1) return x%p;
    if (y==0) return 1;
    if (y&1){
        ll t=fastpow(x,y>>1);
        return (((t*t)%p)*x)%p;
    }else{
        ll t=fastpow(x,y>>1);
        return (t*t)%p;
    }
}
ll inv(ll x){
    return fastpow(x,p-2);
}
int main(){
    scanf("%I64d%I64d%I64d", &n, &p, &r);
    if (n>=2*p){
        if (r==0){
            printf("%I64d %I64d\n", p, p-1);
        }else{
            printf("-1 -1\n");
        }
    }else if (n>=p){
        if (r==0){
            if (n==2){
                printf("-1 -1\n");
            }else if (p==2){
                printf("3 2\n");
            }else{
                printf("2 1\n");
            }
        }else{
            ll ans=1;
            for(ll i=2;i<=n-p;i++){
                ans=(ans*i)%p;
            }
            ans=p-ans;
            ans=(r*inv(ans))%p;
            printf("%I64d %I64d\n", p, ans);
        }
    }else{
        if (r==0){
            printf("-1 -1\n");
            return 0;
        }
        ll mul=1;
        for(ll i=2;i<=n;i++){
            mul=(mul*i)%p;
        }
        mul=(r*inv(mul))%p;
        for(ll i=n;i>=2;i--){
            ll t=(mul*i)%p;
            if (t<i){
                printf("%I64d %I64d\n", i, t);
                return 0;
            }
        }
        printf("-1 -1\n");
    }return 0;
}
