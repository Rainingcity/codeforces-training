#include <iostream>
#include <cstdio>
using namespace std;
string s;
int n;
int main(){
	cin>>s;
	n=s.length();
	int mx=0, mi=0;
	int mxid=-1, miid=-1;
	int cur=0;
	for(int i=0;i<n;i++){
		if (s[i]=='R') cur++;
		else cur--;
		if (cur>mx){
			mx=cur;
			mxid=i;
		}
		if (cur<mi){
			mi=cur;
			miid=i;
		}
	}
	if (mxid<miid){
		mxid=mxid^miid;
		miid=mxid^miid;
		mxid=mxid^miid;
	}
	printf("%d %d\n", miid+2, mxid+1);
	return 0;
}
