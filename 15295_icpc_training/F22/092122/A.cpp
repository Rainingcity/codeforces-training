#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <utility>
#include <cmath>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

int maxi(int x, int y){return x<y?y:x;}
int mini(int x, int y){return x<y?x:y;}

int n,m;
string s;
vector<ll> v;

int main(){
	string s;cin>>s;
	n=s.length();
	v.clear();
	int st=0,ed=n-1;
	while(st<ed && (s[st]=='o' || s[st+1]=='o')) st++;
	while(st<=ed && (s[ed]=='o' || s[ed-1]=='o')) ed--;
	if (st>=ed){
		cout<<0<<endl;
		return 0;
	}

	ll cntv=0;
	ll cnto=0;
	bool mode=1;
	for(int i=st;i<=ed;i++){
		if (s[i]=='v'){
			if (mode) cntv++;
			else if (s[i-1]=='v'){
				mode=1;
				v.push_back(-cnto);
				cntv=2;
				cnto=0;
			}
		}else{
			if (mode){
				mode=0;
				v.push_back(cntv-1);
				cntv=0;
				cnto=1;
			}else cnto++;
		}
	}
	if (mode) v.push_back(cntv-1);
	else v.push_back(cnto);

	m=v.size();
	if (m<3){
		cout<<0<<endl;
		return 0;
	}

	// for(int i=0;i<m;i++) cout<<v[i]<<" ";
	// cout<<endl;

	ll lsum=v[0];
	ll rsum=0;
	for(int i=1;i<m;i++) if (v[i]>0) rsum+=v[i];

	ll cnt=0;
	for(int i=1;i<m;i++){
		if (v[i]<0){
			cnt+=lsum*rsum*(-v[i]);
		}else{
			lsum+=v[i];
			rsum-=v[i];
		}
	}
	cout<<cnt<<endl;
	return 0;
}
