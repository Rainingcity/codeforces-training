#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cstdlib>
using namespace std;
typedef long long ll;
int n,k;
int a[100100];
char s[1000100];
int b[100100],cnt[100100];
int fnd(int x,int st){
    int l=0,r=st-1;
    while (l<=r){
        int mid=(l+r)>>1;
        if (b[mid]==x) return mid;
        if (b[mid]<x) l=mid+1;
        else r=mid-1;
    }return -1;
}
int main(){
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        scanf("%s", s);
        int len=strlen(s);
        for(int j=0;j<len;j++) a[i]^=(1<<(s[j]-'a'));
    }
    sort(a,a+n);
    int cur=0;k=0;
    for(int i=1;i<n;i++){
        if (a[i]!=a[i-1]){
            b[k]=a[cur];
            cnt[k++]=i-cur;
            cur=i;
        }
    }
    b[k]=a[cur];cnt[k++]=n-cur;
    ll ans=0;
    for(int i=0;i<k;i++){
        ans+=((ll)cnt[i]*cnt[i]-cnt[i])>>1;
        for(int j=0;j<26;j++){
            if ((b[i]^(1<<j))>b[i]) continue;
            int t=fnd(b[i]^(1<<j),i);
            if (t!=-1) ans+=cnt[t]*cnt[i];
        }
    }printf("%I64d\n", ans);
    return 0;
}
