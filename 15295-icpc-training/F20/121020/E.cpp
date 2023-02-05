#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
int n;
double v,u;
vector<double> dat;
int main(){
	cin>>n>>v>>u;
	for(int i=0;i<n;i++){
		double x;cin>>x;
		dat.push_back(x);
	}
	sort(dat.begin(),dat.end());
	double ans = (double)dat[n-1]/v;
	double cur_time=0;
	double sucked=0;
	for(int i=n-1;i>=1;i--){
		double suck_speed = (double)u/(n-i);
		double suck_vap_time = (double)(dat[i]-cur_time*v)/(suck_speed+v);
		double suck_time = (double)(dat[i]-dat[i-1])/suck_speed;
		if (suck_vap_time < suck_time){
			cur_time += suck_vap_time;
			ans = min(ans, cur_time);
			break;
		}else{
			cur_time += suck_time;
		}
	}
	if (dat[0] > cur_time*v){
		cur_time += (double)(dat[0]-cur_time*v)/((double)u/n+v);
		ans = min(ans, cur_time);
	}
	cout.precision(10);
	cout<<ans*u<<endl;
	return 0;
}
