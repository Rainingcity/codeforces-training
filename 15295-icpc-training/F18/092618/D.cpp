#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
using namespace std;
char a[1000100][10];
char b[1000100][10];
int n;
int a1[1000100];
int b1[1000100];
int c[1000100];
bool cmp(int x,int y){
    return strcmp(a[x],a[y])<0;
}
int bifnd(int x){
    int l=0,r=n-1;
    while(l<=r){
        int mid=(l+r)>>1;
        int tt=strcmp(a[a1[mid]],b[x]);
        if (tt==0) return mid;
        else if (tt>0) r=mid-1;
        else l=mid+1;
    }return -1;
}
int main(){
    int T;scanf("%d", &T);
    while(T--){
        scanf("%d", &n);
        for(int i=0;i<n;i++) a1[i]=i;
        for(int i=0;i<n;i++) c[i]=0;
        for(int i=0;i<n;i++){
            scanf("%s", a+i);
        }
        for(int i=0;i<n;i++) scanf("%s", b+i);
        sort(a1,a1+n,cmp);
        for(int i=0;i<n;i++){
            b1[bifnd(i)]=i;
            //            printf("%d\n", bifnd(i));
        }
        for(int i=0;i<n;i++){
            if (a1[i]<b1[i]) c[a1[i]]++,c[b1[i]]--;
            else c[b1[i]]++,c[a1[i]]--;
        }
        //        for(int i=0;i<n;i++) printf("%d %d\n", a1[i], b1[i]);
        int s=0,k=0;bool F=0;
        for(int i=0;i<n;i++){
            s+=c[i];
            if (s==0){
                if (F) printf(" ");
                printf("%d", i-k+1);k=i+1;F=1;
            }
        }puts("");
    }
}

