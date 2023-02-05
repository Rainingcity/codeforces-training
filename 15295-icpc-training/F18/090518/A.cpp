#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;
char a[200];
int b[200];
int main(){
    scanf("%s", a);
    char cur = 'Q';
    int k=0;b[0]=0;
    for(int i=0;i<strlen(a);i++){
        if(a[i] != 'Q' && a[i] != 'A') continue;
        if(a[i] == 'Q'){
            if (cur == 'Q') b[k]++;
            else{
                cur='Q';k++;b[k]=1;
            }
        }else{
            if (cur == 'A') b[k]++;
            else{
                cur='A';k++;b[k]=1;
            }
        }
    }k++;
    int sum =0;
    for(int i=0;i<k;i+=2){
        for(int j=i+1;j<k;j+=2){
            for(int l=j+1;l<k;l+=2){
                sum+=b[i]*b[j]*b[l];
            }
        }
    }printf("%d\n", sum);
    return 0;
}
