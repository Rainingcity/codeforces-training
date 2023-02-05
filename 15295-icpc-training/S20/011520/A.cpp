#include <iostream>
using namespace std;
int maxi(int x, int y){return x<y?y:x;}
int n;
int hsh[10010];
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		int x;cin>>x;hsh[x]++;
	}
	int ans=0;
	for(int i=0;i<10010;i++){
		ans=maxi(ans, hsh[i]);
	}
	cout<<ans<<endl;
}
