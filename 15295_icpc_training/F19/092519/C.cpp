#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>
using namespace std;
typedef long long ll;
typedef long double ld;
const ld eps=1e-7;
int n;
struct cord{
	ld x;ld y;
	cord(){}
	cord(int _x, int _y){x=_x;y=_y;}
	cord(ll _x, ll _y){x=_x;y=_y;}
	cord(ld _x, ld _y){x=_x;y=_y;}
	bool operator== (cord b){
		return (x==b.x) && (y==b.y);
	}
};
vector<cord> v;
ld calc_dist_square(cord x, cord y){
	return (x.x-y.x)*(x.x-y.x)+(x.y-y.y)*(x.y-y.y);
}
cord midpoint(cord x, cord y){
	return cord((x.x+y.x)/2,(x.y+y.y)/2);
}
bool check(cord x, ld d2){
	for(int i=0;i<n;i++){
		if (calc_dist_square(v[i], x)>d2+eps) return false;
//		cout<<calc_dist_square(v[i], x)<<endl;
	}
	return true;
}
ld get_x2(cord x){
	return x.x*x.x+x.y*x.y;
}
void get_center(cord x, cord y ,cord z, ld& d2, cord& c){
	d2=-1;
	if (x==y || y==z || x==z) return;
	ld t=(x.x-y.x)*(x.y-z.y)-(x.y-y.y)*(x.x-z.x);
	if (t<=eps && t>=-eps) return;
	ld x2=get_x2(x);
	ld y2=get_x2(y);
	ld z2=get_x2(z);
	c.x=((x.y-z.y)*(x2-y2)-(x.y-y.y)*(x2-z2))/2/t;
	c.y=((x.x-y.x)*(x2-z2)-(x.x-z.x)*(x2-y2))/2/t;
	d2=calc_dist_square(c, x);
}
int main(){
	cin >> n;
	cout.precision(15);
	for(int i=0;i<n;i++){
		int x,y;cin>>x>>y;
		v.push_back(cord(x,y));
	}
	if (n==1){
		cout<<0<<endl;
		return 0;
	}
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			ld t=calc_dist_square(v[i],v[j]);t=t/4;
			cord c=midpoint(v[i],v[j]);
			if (check(c, t)){
				ld r=sqrt(t);
				cout<<r<<endl;
				return 0;
			}
		}
	}
	ld mx=1e12;
	cord mxc;
	for(int i=0;i<n-2;i++){
		for(int j=i+1;j<n-1;j++){
			for(int k=j+1;k<n;k++){
				ld d2;
				cord c;
				get_center(v[i],v[j],v[k], d2, c);
				if (d2<mx && check(c, d2)){
					mx=d2;mxc=c;
				}
//				cout<<d2<<" "<<c.x<<" "<<c.y<<endl;
			}
		}
	}
	cout<<sqrt(mx)<<endl;
	return 0;
}
