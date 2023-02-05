/*
 * Codeforces 1181A
 * Chunga-Changa
 */

#include <cstdio>
using namespace std;
typedef long long ll;
ll mini(ll x, ll y){return x<y?x:y;}
ll n,m,k;
int main(){
    scanf("%I64d%I64d%I64d", &n, &m, &k);
    ll ans = n/k+m/k;
    n%=k;m%=k;
    if (n+m>=k){
        printf("%I64d %I64d\n", ans+1ll, mini(k-n,k-m));
    }else{
        printf("%I64d 0\n", ans);
    }
    return 0;
}
