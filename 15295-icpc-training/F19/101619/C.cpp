#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
typedef long double ld;
const ld eps = 1e-18;
int n;
ld absi(ld x){if (x<=eps) return -x; else return x;}
int coords(ld cosine, ld sine){
	if (absi(sine)<=eps && absi(cosine-1)<=eps) return 0;
	if (cosine>=eps && sine>=eps) return 1;
	if (absi(cosine)<=eps && absi(sine-1)<=eps) return 2;
	if (-cosine>=eps && sine>=eps) return 3;
	if (absi(sine)<=eps && absi(cosine+1)<=eps) return 4;
	if (-cosine>=eps && -sine>=eps) return 5;
	if (absi(cosine)<=eps && absi(sine+1)<=eps) return 6;
	if (cosine>=eps && -sine>=eps) return 7;
	return 7;
}
struct node{
	ld x;
	ld y;
	ld cosine;
	ld sine;
	ld sqsumroot;
	int id;
	node(){}
	node(int _x, int _y, int i){
		x=_x;y=_y;
		sqsumroot=sqrt(x*x+y*y);
		cosine=x/sqsumroot;
		sine=y/sqsumroot;
		id=i;
	}
	node(ld cosine_diff, ld sine_diff, int i){
		x=cosine_diff;y=sine_diff;
		sqsumroot=1;
		cosine=cosine_diff;
		sine=sine_diff;
		id=i;
	}
};
bool cmp(node x, node y){
	int xc=coords(x.cosine, x.sine);
	int yc=coords(y.cosine, y.sine);
	if (xc!=yc) return xc<yc;
	else{
		if (xc&1){
			if (xc==1){
				if (absi(y.cosine)>0.5) return y.sine-x.sine>=eps;
				else return x.cosine-y.cosine>=eps;
			}else if (xc==3){
				if (absi(y.cosine)>0.5) return x.sine-y.sine>=eps;
				else return x.cosine-y.cosine>=eps;
			}else if (xc==5){
				if (absi(y.cosine)>0.5) return x.sine-y.sine>=eps;
				else return y.cosine-x.cosine>=eps;
			}else{
				if (absi(y.cosine)>0.5) return y.sine-x.sine>=eps;
				else return y.cosine-x.cosine>=eps;
			}
		}else return 0;
	}
	return 0;
}
vector<node> v;
int main(){
	cin>>n;
//	cout.precision(15);
	for(int i=0;i<n;i++){
		int x,y;cin>>x>>y;
		v.push_back(node(x,y,i+1));
	}
	sort(v.begin(), v.end(), cmp);
//	for(int i=0;i<n;i++) cout<<v[i].cosine<<" "<<v[i].sine<<" "<<v[i].id<<endl;
	node stx=v[n-1], sty=v[0];
	ld cosine_diff=stx.cosine*sty.cosine+stx.sine*sty.sine;
	ld sine_diff=sty.sine*stx.cosine-sty.cosine*stx.sine;
	if (coords(cosine_diff,sine_diff)>3){
		sine_diff=-sine_diff;
	}
	node mn (cosine_diff,sine_diff,0);
//	cout<<cosine_diff<<" "<<sine_diff<<endl;
	for(int i=1;i<n;i++){
		node x=v[i-1], y=v[i];
		cosine_diff=x.cosine*y.cosine+x.sine*y.sine;
		sine_diff=y.sine*x.cosine-y.cosine*x.sine;
//		cout<<cosine_diff<<" "<<sine_diff<<" "<<coords(cosine_diff,sine_diff)<<endl;
		if (coords(cosine_diff,sine_diff)>3){
			sine_diff=-sine_diff;
		}
		node tmp (cosine_diff,sine_diff,i);
		if (cmp(tmp,mn)){
			mn=tmp;
		}
	}
	cout<<v[mn.id].id<<" "<<v[(mn.id==0?n-1:mn.id-1)].id<<endl;
	return 0;
}
