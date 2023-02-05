/*
 * Codeforces 1179A
 * Valeriy and Deque
 */

#include <cstdio>
#include <iostream>
using namespace std;
typedef long long ll;
int n, q;
int dat[200100];
int ansA[100100];
int ansB[100100];
int main(){
	cin>>n>>q;
	int mx=0, pos=0;
	for(int i=0;i<n;i++){
		cin>>dat[i];
		if (mx<dat[i]){
			mx=dat[i];
			pos=i;
		}
	}
	for(int i=0;i<pos;i++){
		ansA[i]=dat[i];
		ansB[i]=dat[i+1];
		if (dat[i]>dat[i+1]){
			dat[i+n]=dat[i+1];
			dat[i+1]=dat[i];
		}else{
			dat[i+n]=dat[i];
		}
	}
	for(int t=0;t<q;t++){
		ll x;cin>>x;
		if (x>pos){
			x=(x-pos-1)%(ll)(n-1);
			cout<<mx<<" "<<dat[x+pos+1]<<endl;
		}else{
			cout<<ansA[x-1]<<" "<<ansB[x-1]<<endl;
		}
	}
	return 0;
}
