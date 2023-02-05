#include<cstdio>
using namespace std;
typedef long long ll;
const ll BIG = 1000000007;
ll n,m,c;
ll multi(ll x, ll y){
    ll ans=x;
    for(ll i=1;i<y;i++){
        ans=(ans*x)%BIG;
    }return ans;
}
ll multin2(ll x){
    return multi(multi(x,n),n);
}
ll gcd(ll x, ll y){
    if (y==0) return x;
    return gcd(y, x%y);
}
ll inv(ll x){
    if (x==1) return 1;
    if (BIG % x <= (x>>1)) return ((BIG-BIG/x)*inv(BIG%x))%BIG;
    else return ((BIG/x+1)*inv(x-BIG%x))%BIG;
}
int main(){
    scanf("%I64d%I64d%I64d", &n, &m, &c);
    ll res = multin2(multi(c,m));
    for(int i=1;i<m;i++){
        res = (res + multin2(multi(c,gcd(m,i))))%BIG;
    }
    res = (res * inv(m))%BIG;
    printf("%I64d\n", res);
    return 0;
}
