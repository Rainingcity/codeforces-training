#include <iostream>
#include <cmath>
#include <utility>
using namespace std;
typedef long double ld;
typedef long long ll;
const ld inf = 1e17;
ld a,b,c,d;
ld absi(ld x){return x<0?-x:x;}
ld maxi(ld x, ld y){return x<y?y:x;}
ld maxi(ld a1, ld a2, ld a3, ld a4){
	return maxi(absi(a1), maxi(absi(a2), maxi(absi(a3), absi(a4))));
}
ld mini(ld x, ld y){return x>y?y:x;}
ld mini(ld a1, ld a2, ld a3, ld a4){
	return mini(absi(a1), mini(absi(a2), mini(absi(a3), absi(a4))));
}
pair<ld,ld> solve(ld c1, ld c2, ld c3){
	ld delta=c2*c2-4*c1*c3;
	if (delta<0) return make_pair(inf,inf);
	delta=sqrt(delta);
	return make_pair((-c2+delta)/(2*c1), (-c2-delta)/(2*c1));
}
int main(){
	cin>>a>>b>>c>>d;
	cout.precision(18);
	if ((ll)a*(ll)d==(ll)b*(ll)c){
		cout<<0<<endl;
		return 0;
	}
	ld det=a*d-b*c;
	ld ans=absi(det/maxi(a+b+c+d, a-b+c-d, a-b-c+d, a+b-c-d));
	pair<ld,ld> x=solve(2, a+b-c+d, det);
	ans=mini(ans, ans, absi(x.first), absi(x.second));
	x=solve(2, a-b+c+d, det);
	ans=mini(ans, ans, absi(x.first), absi(x.second));
	x=solve(-2, -a+b+c+d, det);
	ans=mini(ans, ans, absi(x.first), absi(x.second));
	x=solve(-2, a+b+c-d, det);
	ans=mini(ans, ans, absi(x.first), absi(x.second));
	cout<<ans<<endl;
	return 0;
}
