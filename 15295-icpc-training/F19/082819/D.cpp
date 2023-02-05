#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int n,k,x;
int v[2][1030];
int main(){
	cin>>n>>k>>x;
	for(int i=0;i<n;i++){
		int y;cin>>y;
		v[0][y]++;
	}
	bool prev=0;
	for(int cnt=0;cnt<k;cnt++){
		int j=0;
		bool cur=!prev;
		for(int i=0;i<1024;i++) v[cur][i]=0;
		for(int i=0;i<1024 && j<n;i++){
			if (v[prev][i]==0) continue;
			int chg=0;
			if (v[prev][i]&1){
				if (j&1){
					chg=v[prev][i]>>1;
				}else{
					chg=(v[prev][i]>>1)+1;
				}
			}else chg=v[prev][i]>>1;
			v[cur][i]+=v[prev][i]-chg;
			v[cur][i^x]+=chg;
			j+=v[prev][i];
//			cout<<i<<" "<<v[prev][i]<<" "<<chg<<" "<<(i^x)<<endl;
		}
		prev=cur;
	}
	int mi, mx;
	for(int i=0;i<1024;i++) if (v[prev][i]!=0){mi=i;break;}
	for(int i=1023;i>=0;i--) if (v[prev][i]!=0){mx=i;break;}
	cout<<mx<<" "<<mi<<endl;
}
