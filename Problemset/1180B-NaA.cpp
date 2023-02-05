/*
 * Codeforces 1180B
 * Nick and Array
 */

#include <cstdio>
using namespace std;
int n;
int dat[100100];
int main(){
    scanf("%d", &n);
    int mx=0, mxi=-1;
    for(int i=0;i<n;i++){
        scanf("%d", dat+i);
        if (dat[i]>=0) dat[i]=-dat[i]-1;
        if (-dat[i]>mx){
            mx=-dat[i];
            mxi=i;
        }
    }
    if (n&1) dat[mxi]=-dat[mxi]-1;
    for(int i=0;i<n;i++){
        if (i) printf(" ");
        printf("%d", dat[i]);
    }
    puts("");
    return 0;
}
