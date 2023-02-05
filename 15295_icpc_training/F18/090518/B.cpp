#include<cstdio>
using namespace std;
int n;
int maxi(int x,int y){
    return (x<y?y:x);
}
int maxi(int x,int y,int z){
    return maxi(maxi(x,y),z);
}
struct tree{
    int height;
    int loc;
    tree(){}
    tree(int _loc, int _height){
        loc=_loc;
        height=_height;
    }
}a[1001000];
int dp[100100][3];
int main(){
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        int x, y;
        scanf("%d%d", &x, &y);
        a[i] = tree(x, y);
    }
    dp[0][0]=0;
    dp[0][1]=1;
    dp[0][2]=1;
    for(int i=1;i<n;i++){
        bool F=a[i-1].height<(a[i].loc-a[i-1].loc);
        int t=maxi(dp[i-1][0],dp[i-1][1]);
        dp[i][0]=t;
        if (F) dp[i][0]=maxi(dp[i][0],dp[i-1][2]);
        if (a[i].height>=a[i].loc-a[i-1].loc){
            dp[i][1]=0;
        }else if (a[i-1].height+a[i].height<a[i].loc-a[i-1].loc){
            dp[i][1]=maxi(t,dp[i-1][2])+1;
        }else if (F){
            dp[i][1]=maxi(t+1,dp[i-1][2]);
        }else{
            dp[i][1]=t+1;
        }
        dp[i][2]=dp[i][0]+1;
    }printf("%d\n", maxi(dp[n-1][0],dp[n-1][1],dp[n-1][2]));
    return 0;
}
