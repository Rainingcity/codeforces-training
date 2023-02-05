#include <iostream>
using namespace std;

int main(){
	int p,m,x;
	cin>>p>>m>>x;
	ll px = p;
	while(px<=x) px *= p;

	while(x != 0){
		px /= p;
		cur = x / px;
	}
}
