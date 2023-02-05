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

const ll MOD=1000000007;

int maxi(int x, int y){return x<y?y:x;}
int mini(int x, int y){return x<y?x:y;}

int n,m;
vector<int> v;
vector<int> bc;
vector<int> mxp;

int main(){
	cin>>n;
	v.clear();
	bc.clear();
	mxp.clear();

	int mx=0,mxpos=0;
	for(int i=0;i<n;i++){
		int x;cin>>x;v.push_back(x);
		if (x>mx){
			mx=x;mxpos=i;
		}
		mxp.push_back(mxpos);
	}

	// for(int i=0;i<n;i++) cout<<mxp[i]<<" ";
	// cout<<endl;

	int bcpos=mxp[n-1];
	bc.push_back(bcpos);
	while(bcpos!=0){
		bcpos=mxp[bcpos-1];
		bc.push_back(bcpos);
	}
	m=bc.size();

	// cout<<m<<endl;
	// for(int i=0;i<m;i++) cout<<bc[i]<<" ";
	// cout<<endl;

	ll res=1;
	for(int i=m-1;i>0;i--){
		res=(res*(bc[i-1]-bc[i]+1))%MOD;
	}
	cout<<res<<endl;
	return 0;
}
