#include<cstdio>
using namespace std;
int f[2000100];
int main(){
    int x,y;scanf("%d%d", &x, &y);
    if (x>y){
        int t=x;
        x=y;y=t;
    }
    int k=1;
    bool F=0;
    for(int i=2;i<=x && i<=y;i++){
        if (f[i]==0){
            f[i+k]=1;
            if (i==x && i+k==y){
                F=1;
            }
            k++;
        }
    }
    if (F==0) puts("Alice");
    else puts("Britney");
    return 0;
}

