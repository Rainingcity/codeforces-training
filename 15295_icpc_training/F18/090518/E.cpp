#include<cstdio>
#include<algorithm>
using namespace std;
int n,h;
double p;
int loc[2018];
double dp[2018][2018][2][2];
int mini(int x,int y){
    return (x<y?x:y);
}
int main(){
    scanf("%d%d%lf", &n, &h, &p);
    for(int i=0;i<n;i++) scanf("%d", loc+i);
    sort(loc,loc+n);
    for(int i=1;i<n-1;i++){
        dp[i][i][0][0]=dp[i][i][1][0]=0.5*mini(h,loc[i]-loc[i-1])*p;
        dp[i][i][0][1]=dp[i][i][1][1]=0.5*mini(h,loc[i+1]-loc[i])*(1-p);
    }
    if (n>1){
        dp[0][0][0][0]=dp[0][0][1][0]=0.5*h*p;
        dp[0][0][0][1]=dp[0][0][1][1]=0.5*mini(h,loc[1]-loc[0])*(1-p);
        dp[n-1][n-1][0][0]=dp[n-1][n-1][1][0]=0.5*mini(h,loc[n-1]-loc[n-2])*p;
        dp[n-1][n-1][0][1]=dp[n-1][n-1][1][1]=0.5*h*(1-p);
    }else{
        dp[0][0][0][0]=dp[0][0][1][0]=0.5*h*p;
        dp[0][0][0][1]=dp[0][0][1][1]=0.5*h*(1-p);
    }
    for(int c=1;c<n;c++){
        for(int i=0;i<n-c;i++){
            int j=i+c;
            bool F=(loc[i+1]-loc[i]<h);
            int k=h;
            if (i) k=mini(k,loc[i]-loc[i-1]);
            dp[i][j][0][0]=0.5*(dp[i+1][j][0][0]+dp[i+1][j][0][1]+dp[i+1][j][1][0]+dp[i+1][j][1][1]+k)*p;
            if (F) dp[i][j][0][1]=0.5*(dp[i+1][j][0][1]*2/(1-p)+loc[i+1]-loc[i])*(1-p);
            else{
                dp[i][j][0][1]=dp[i+1][j][0][0]+dp[i+1][j][0][1]+dp[i+1][j][1][0]+dp[i+1][j][1][1];
                dp[i][j][0][1]+=h*(0.5+0.5*(1-p))+(2*h<=loc[i+1]-loc[i]?h:loc[i+1]-loc[i]-h)*0.5*p;
                dp[i][j][0][1]*=0.5*(1-p);
            }
            F=(loc[j]-loc[j-1]<h);
            k=h;
            if (j<n-1) k=mini(k,loc[j+1]-loc[j]);
            dp[i][j][1][1]=0.5*(dp[i][j-1][0][0]+dp[i][j-1][0][1]+dp[i][j-1][1][0]+dp[i][j-1][1][1]+k)*(1-p);
            if (F) dp[i][j][1][0]=0.5*(dp[i][j-1][1][0]*2/p+loc[j]-loc[j-1])*p;
            else{
                dp[i][j][1][0]=dp[i][j-1][0][0]+dp[i][j-1][0][1]+dp[i][j-1][1][0]+dp[i][j-1][1][1];
                dp[i][j][1][0]+=h*(0.5+0.5*p)+(2*h<=loc[j]-loc[j-1]?h:loc[j]-loc[j-1]-h)*0.5*(1-p);
                dp[i][j][1][0]*=0.5*p;
            }
        }
    }printf("%lf\n", dp[0][n-1][0][0]+dp[0][n-1][1][0]+dp[0][n-1][0][1]+dp[0][n-1][1][1]);
    return 0;
}
