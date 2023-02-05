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
int maxi(int x, int y, int z){return maxi(maxi(x, y), z);}
int mini(int x, int y, int z){return mini(mini(x, y), z);}

int n;
string s;

bool pac(int steps){
	// cout<<steps<<endl;
	int far=-1;
	bool left=false;
	for(int i=0;i<n;i++){
		if (s[i]=='*'){
			if (left) continue;
			if (far<i){
				left=true;
				far=i;
			}
		}else if (s[i]=='P'){
			if (!left){
				far=i+steps;
			}else if(i-far<=steps){
				left=false;
				far=maxi(i, far+(steps-i+far), i+(steps-i+far)/2);
			}else return false;
		}
		// cout<<i<<" "<<far<<" "<<left<<endl;
	}
	return !left;
}

int main(){
	cin>>n>>s;
	int l=0,r=n*2;
	while(l<r){
		int mid=(l+r)>>1;
		if (pac(mid)) r=mid;
		else l=mid+1;
	}
	cout<<r<<endl;
}
