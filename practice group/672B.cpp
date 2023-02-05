#include <cstdio>
#include <utility>
#include <algorithm>
#include <vector>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;

bool cmp2(pii x, pii y){
    if (x.second != y.second) return x.second < y.second;
    else return x.first > y.first;
}

ll comb(ll x){
    return x * (x-1) / 2;
}

void work(){
    int n;scanf("%d", &n);
    vector<pii> v{};
    for(int i=0; i<n; i++){
        int x;scanf("%d", &x);
        v.push_back(make_pair(i, x));
    }
    sort(v.begin(), v.end(), cmp2);
    int ub=1;
    while(ub<=v[0].second) ub<<=1;
    int st=0;
    ll ans=0;
    for(int i=1; i<n; i++){
        if (v[i].second<ub) continue;
        ans += comb(i-st);
        st=i;
        while(ub<=v[i].second) ub<<=1;
    }
    ans += comb(n-st);
    printf("%lld\n", ans);
}

int main(){
    int T;scanf("%d", &T);
    while(T--){
        work();
    }
}
