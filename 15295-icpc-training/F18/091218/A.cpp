#include<cstdio>
using namespace std;
int n,m;
int main(){
    scanf("%d%d", &n, &m);
    int num=0;
    while(m>n){
        if (((m>>1)<<1)==m){
            m=m>>1;
            num++;
        }else{
            m+=1;
            num++;
        }
    }
    printf("%d\n", num+n-m);
    return 0;
}
