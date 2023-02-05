#include<cstdio>
using namespace std;
int main(){
    int n;scanf("%d", &n);
    int k=n>>1;
    for(int i=0;i<n;i++){
        for(int j=1;j<=k;j++){
            printf("%d %d\n", i+1, (i+j)%n+1);
        }
    }return 0;
}

