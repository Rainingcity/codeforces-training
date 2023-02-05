/*
 * Codeforces 1167B
 * Lost Numbers
 */

#include<cstdio>
#include<cstring>
using namespace std;
int x1, x2, x3, x4;
int ans[6];
int main(){
	printf("? 1 2\n");
	fflush(stdout);
	scanf("%d", &x1);
	printf("? 3 4\n");
	fflush(stdout);
	scanf("%d", &x2);
	printf("? 1 4\n");
	fflush(stdout);
	scanf("%d", &x3);
	printf("? 3 5\n");
	fflush(stdout);
	scanf("%d", &x4);
	if (x1%7==0){
		if (x3%7==0){
			ans[0]=42;
			ans[1]=x1/42;
			ans[3]=x3/42;
			ans[2]=x2/ans[3];
			ans[4]=x4/ans[2];
			ans[5]=7418880/x1/x2/ans[4];
		}else{
			ans[1]=42;
			ans[0]=x1/42;
			ans[3]=x3/ans[0];
			ans[2]=x2/ans[3];
			ans[4]=x4/ans[2];
			ans[5]=7418880/x1/x2/ans[4];
		}
	}else if (x2%7==0){
		if (x3%7==0){
			ans[3]=42;
			ans[2]=x2/42;
			ans[0]=x3/42;
			ans[1]=x1/ans[0];
			ans[4]=x4/ans[2];
			ans[5]=7418880/x1/x2/ans[4];
		}else{
			ans[2]=42;
			ans[3]=x2/ans[2];
			ans[0]=x3/ans[3];
			ans[1]=x1/ans[0];
			ans[4]=x4/ans[2];
			ans[5]=7418880/x1/x2/ans[4];
		}
	}else{
		if (x4%7==0){
			ans[4]=42;
			ans[5]=7418880/x1/x2/ans[4];
			ans[2]=x4/42;
			ans[3]=x2/ans[2];
			ans[0]=x3/ans[3];
			ans[1]=x1/ans[0];
		}else{
			ans[5]=42;
			ans[4]=7418880/x1/x2/42;
			ans[2]=x4/ans[4];
			ans[3]=x2/ans[2];
			ans[0]=x3/ans[3];
			ans[1]=x1/ans[0];
		}
	}
	printf("! %d %d %d %d %d %d\n", ans[0], ans[1], ans[2], ans[3], ans[4], ans[5]);
	fflush(stdout);
	return 0;
}
