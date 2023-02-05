#include <iostream>
#include <cmath>
using namespace std;
const double eps = 1e-10;
double absi(double x){return x<0?-x:x;}
void solve(){
	double w,l,h;
	cin>>h>>l>>w;
	double ans = h * 2.0 / w;
	ans = (sqrt(ans*ans+1)-1) / ans;
	double thresh = (h-l) * sqrt(w*w+4*h*h)/ ans / h / 2.0;
	ans = w * l / (ans + 1.0) / h / 2;

	if (thresh - ans < eps){
		ans = (h-l+w/2) - sqrt(w*(h-l));
	}

	cout<<ans<<endl;
	return;
}
int main(){
	int T;cin>>T;
	cout.precision(10);
	while(T--){
		solve();
	}
}
