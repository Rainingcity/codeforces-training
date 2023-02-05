#include<cstdio>
#include<algorithm>
using namespace std;
int n;
char a[30000];
int s[30000];
bool cmp(int x,int y){
    return (a[x]==a[y]?x<y:a[x]<a[y]);
}
int main(){
    int T;scanf("%d", &T);
    while(T--){
        scanf("%d", &n);
        scanf("%s", a);
        for(int i=0;i<n;i++) s[i]=i;
        sort(s,s+n,cmp);
        int prev=0,ans=0;
        for(int i=0;i<n;i++){
            if (i!=n-1 && a[s[i]]==a[s[i+1]]) continue;
            ans+=(s[i]-i)*(i-prev+1);prev=i+1;
        }
        printf("%d\n", ans*5);
    }
}
