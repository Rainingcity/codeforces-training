#include <iostream>
#include <cmath>
#include <utility>
using namespace std;
typedef long long ll;
ll n;
pair<ll,ll> count_cycle(ll x){
	ll y=(ll)sqrt(x/3)+1;
	while(y*(y+1)*3>x) y--;
	return make_pair(y, x-y*(y+1)*3);
}
int main(){
	cin>>n;
	auto [m, rem] = count_cycle(n);
	if (rem==0) cout<<m*2<<" "<<0<<endl;
	else{
		m++;
		if (rem<=m){
			cout<<m*2-rem<<" "<<rem*2<<endl;
		}else if (rem<=2*m){
			cout<<m*3-rem*2<<" "<<m*2<<endl;
		}else if (rem<=3*m){
			cout<<m-rem<<" "<<m*6-rem*2<<endl;
		}else if (rem<=4*m){
			cout<<rem-5*m<<" "<<m*6-rem*2<<endl;
		}else if (rem<=5*m){
			cout<<rem*2-m*9<<" "<<-m*2<<endl;
		}else{
			cout<<rem-m*4<<" "<<rem*2-m*12<<endl;
		}
	}
	return 0;
}
