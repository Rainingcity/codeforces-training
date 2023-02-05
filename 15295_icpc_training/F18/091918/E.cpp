#include<cstdio>
using namespace std;
int n,k;
int a[1010],b[1010],c[1010];

int main(){
    scanf("%d%d", &k, &n);
    for(int i=0;i<n;i++){
        int x;scanf("%d", &x);
        a[x]++;
    }
    int maxx=0;
    for(int i=1;i<=k;i++){
        b[a[i]]+=i;c[a[i]]++;
        if (c[a[i]]>=2) maxx=i;
    }
    if (maxx==0 && k==3){
        int ans=0;
        for(int i=2;i<k;i++) if (c[i-1]==1 && c[i]==1 && c[i+1]==1){ans=i;break;}
        if (ans==0) puts("*");
        else{
            int ans1=0;
            for(int i=1;i<=k;i++) if (a[i]==ans-1){ans1=i;break;}
            int ans2=0;
            for(int i=1;i<=k;i++) if (a[i]==ans+1){ans2=i;break;}
            printf("-%d +%d\n", ans2, ans1);
        }
    }else if (maxx!=0 && c[a[maxx]]+c[a[maxx]-1]+c[a[maxx]+1]==k){
        if (c[a[maxx]-1]==1 && c[a[maxx]+1]==1){
            printf("-%d +%d\n", b[a[maxx]+1], b[a[maxx]-1]);
        }else if (c[a[maxx]-1]==1 && c[a[maxx]]==k-1){
            printf("+%d\n", b[a[maxx]-1]);
        }else if (c[a[maxx]+1]==1 && c[a[maxx]]==k-1){
            printf("-%d\n", b[a[maxx]+1]);
        }else puts("*");
    }else puts("*");
    return 0;
}
