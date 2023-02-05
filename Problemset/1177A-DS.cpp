/*
 * Codeforces 1177A
 * Digital Sequence (Easy Edition)
 */

#include <cstdio>
using namespace std;
int k;
int get_digit(int pos, int x){
	while(pos--){
		x/=10;
	}
	return x%10;
}
int main(){
	scanf("%d", &k);
	int cnt = 0;
	for(int i=1;i<=k;i++){
		if (i<10) cnt++;
		else if (i<100) cnt+=2;
		else if (i<1000) cnt+=3;
		else cnt+=4;
		if (cnt>=k){
			printf("%d\n", get_digit(cnt-k, i));
			return 0;
		}
	}
}
