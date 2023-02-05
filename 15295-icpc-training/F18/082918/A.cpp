#include<cstdio>
using namespace std;
int n;
long long a[100100];
int main(){
    scanf("%d", &n);
    for(int i=0;i <n;i++){
        scanf("%I64d", a+i);
    }
    for(int i=0;i<6 && i<n;i++){
        for(int j=i+1;j<7 && j<n;j++){
            if ((a[j]-a[i])%(j-i)!=0) continue;
            long long dd = (a[j]-a[i])/(j-i);
            long long sta = a[i] - dd*i;
            long long x = sta, num=0;
            for(int k=0;k<n;k++){
                if (a[k] !=x) num++;
                x+=dd;
            }
            if (num<=3){
                printf("%I64d", sta);
                for(int i=1;i<n;i++){
                    sta += dd;
                    printf(" %I64d", sta);
                }puts("");
                return 0;
            }
        }
    }
}
