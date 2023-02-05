/*
 * Codeforces 1143A
 * The Doors
 */

#include <cstdio>
using namespace std;
int mini(int x, int y){return x<y?x:y;}
int n;
int l, r;
int main(){
    scanf("%d", &n);l=r=0;
    for(int i=0;i<n;i++){
        int x;scanf("%d", &x);
        if (x) r=i;
        else l=i;
    }
    printf("%d\n", mini(l, r)+1);
    return 0;
}
