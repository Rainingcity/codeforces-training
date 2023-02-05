#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cstdlib>
#include<map>
using namespace std;
typedef long long ll;
int n,k;
int a[100100];
char s[1000100];
map<int,int> Hash;
bool ss[30];
int main(){
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        for(int j=0;j<26;j++) ss[j]=0;
        scanf("%s", s);
        int len=strlen(s);
        for(int j=0;j<len;j++) ss[s[j]-'a']=!ss[s[j]-'a'];
        int mul=1;
        for(int j=0;j<26;j++){
            if (ss[j]) a[i]+=mul;
            mul<<=1;
        }
        if (Hash.find(a[i])!=Hash.end()) Hash[a[i]]++;
        else Hash[a[i]]=1;
    }
    ll ans=0;
    for(int i=0;i<n;i++){
        ans+=Hash[a[i]]-1;
        for(int j=0;j<26;j++){
            int t=a[i]^(1<<j);
            if (Hash.find(t)!=Hash.end()) ans+=Hash[t];
        }
    }
    ans>>=1;
    printf("%I64d\n", ans);
    return 0;
}
