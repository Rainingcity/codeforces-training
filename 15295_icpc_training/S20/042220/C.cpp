#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
const long long MOD=1e9+7;
int n;
vector<bool> f; // prime?
vector<int> v; // prime!
unordered_set<int> s;
int gcd(int x, int y){
    if (y==0) return x;
    return gcd(y, x%y);
}
int main(){
    cin>>n;
    f.resize(40000);
    for(int i=2;i<40000;i++){
        if (!f[i]) v.push_back(i);
        for(auto& j: v){
            if (i*j>=40000) break;
            f[i*j]=true;
            if (i%j==0) break;
        }
    }
    for(int i=0;i<n;i++){
        int x,y;cin>>x>>y;
        int t=gcd(x,y);y/=t;
        bool F=0;
        for(auto& p: v){
            if (p==1) break;
            if (y%p==0){
                s.insert(p);
                while(y%p==0) y/=p;
            }
        }
        if (y!=1) s.insert(y);
    }
    long long ans=1;
    for(auto& p: s){
        ans=(ans*(long long)p)%MOD;
    }
    cout<<ans<<endl;
    return 0;
}
