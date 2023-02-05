#include <iostream>
using namespace std;
int mini(int x, int y){return x<y?x:y;}

int n;

int main(){
	cin>>n;
	int sum = 0, mi = 1010;
	for(int i=0;i<n;i++){
		int x;cin>>x;
		int k = x-(!(x&1));
		mi = mini(k, mi);
		sum += k;
	}
	if (n&1){
		cout<<sum<<endl;
	}else{
		cout<<sum-mi<<endl;
	}
}
