#include<cstdio>
#include<map>
#include<utility>
using namespace std;
int n;
int a[1000100];
map<int,int> mp;
map<int,int> mpr;
int cntl[1000100],cntr[1000100];
int main(){
	scanf("%d", &n);
	for(int i=0;i<n;i++){
		scanf("%d", a+i);
		if (mp.find(a[i])!=mp.end()) mp[a[i]]++;
		else mp.insert(make_pair(a[i], 1));
		cntl[i]=mp[a[i]];
	}
	for(int i=n-1;i>=0;i--){
		if (mp.find(a[i])!=mp.end()) mp[a[i]]++;
		else mp.insert(make_pair(a[i], 1));
		cntr[i]=mp[a[i]];
	}
}
