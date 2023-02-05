#include <iostream>
#include <string>
#include <vector>
using namespace std;
int n,m;
string s;
vector<int> v{};
void Swap(int& x, int& y){
    int t;t=x;x=y;y=t;
}
int main(){
    cin>>n>>m>>s;
    v.resize(26);
    for(int i=0;i<26;i++) v[i]=i;
    for(int i=0;i<m;i++){
        char x, y;cin>>x>>y;
        Swap(v[x-'a'], v[y-'a']);
    }
    vector<int> vr{};
    vr.resize(26);
    for(int i=0;i<26;i++) vr[v[i]]=i;
    for(int i=0;i<n;i++){
        s[i]=vr[s[i]-'a']+'a';
    }
    cout<<s<<endl;
    return 0;
}
