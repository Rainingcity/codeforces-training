#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
int mini(int x, int y){return x<y?x:y;}
int n;
vector<int> v;
int gcd(int x, int y){
	if (y==0) return x;
	return gcd(y,x%y);
}
void solve(){
	int ans=0;
	for(int cnt=n;cnt>2;cnt--){
		int mi=mini(gcd(v[cnt-1],v[1]),gcd(v[0],v[cnt-2]));
		for(int i=1;i<cnt-1;i++){
			mi=mini(mi, gcd(v[i-1],v[i+1]));
		}
		ans+=mi;
		if (mi==gcd(v[cnt-1],v[1])){
			for(int i=1;i<cnt;i++) v[i-1]=v[i];
		}else if (mi==gcd(v[cnt-2],v[0])){
		}else{
			for(int i=1;i<cnt-1;i++){
				if (mi==gcd(v[i-1],v[i+1])){
					for(int j=i+1;j<cnt;j++) v[j-1]=v[j];
				}
			}
		}
	}
	ans+=gcd(v[0],v[1]);
	cout<<ans<<endl;
}
int main(){
	cin>>n;
	while(n!=0){
		v.clear();
		for(int i=0;i<n;i++){
			int x;cin>>x;
			v.push_back(x);
		}
		solve();
		cin>>n;
	}
}
