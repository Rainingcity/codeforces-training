#include <iostream>
using namespace std;
int main(){
	int n;cin>>n;
	long long ans=n;
	for(int i=2;i<=n;i++){
		ans+=(long long)(n/i);
	}
	cout<<ans<<endl;
	return 0;
}
