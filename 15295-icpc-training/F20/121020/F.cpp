#include <iostream>
#include <vector>
#include <utility>
#include <cmath>
#include <deque>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
int n,d;
ll area=0;
vector<pll> dat;
ll cross_product(pll a, pll b){
	return a.first * b.second - a.second * b.first;
}
pll vector_minus(pll a, pll b){
	return make_pair(b.first-a.first, b.second-a.second);
}
long double length(pll a){
	return sqrt(a.first * a.first + a.second * a.second);
}
struct edge{
	pll u,v;
	edge()=default;
	edge(pll a, pll b){
		u=a;v=b;
	}
	pll make_vector(){
		return vector_minus(v, u);
	}
};
edge expand(edge a){
	if (a.u.first==a.v.first){
		if (a.u.second < a.v.second){
			return edge(make_pair(a.u.first + d, a.u.second), make_pair(a.v.first + d, a.v.second));
		}else{
			return edge(make_pair(a.u.first - d, a.u.second), make_pair(a.v.first - d, a.v.second));
		}
	}else{
		if (a.u.first < a.v.first){
			return edge(make_pair(a.u.first, a.u.second - d), make_pair(a.v.first, a.v.second - d));
		}else{
			return edge(make_pair(a.u.first, a.u.second + d), make_pair(a.v.first, a.v.second + d));
		}
	}
}
int main(){
	cin>>n>>d;
	dat.resize(n);
	cin>>dat[0].first>>dat[0].second;
	for(int i=1;i<n;i++){
		cin>>dat[i].first>>dat[i].second;
		area += cross_product(dat[i-1], dat[i]);
	}
	if (area<0){
		for(int i=0,j=n-1;i<j;i++,j--){
			pll t=dat[i];
			dat[i]=dat[j];
			dat[j]=t;
		}
	}
	dat.push_back(dat[0]);
	dat.push_back(dat[1]);
	deque<edge> poly;
	while(!poly.empty()) poly.pop_back();
	edge cur_poly_edge = expand(edge(dat[0], dat[1]));
	for(int i=1;i<=n;i++){
		edge cur_edge (dat[i-1], dat[i]);
		edge nxt_edge (dat[i], dat[i+1]);
		ll dir = cross_product(cur_edge.make_vector(), nxt_edge.make_vector());
		edge nxt_poly_edge = expand(nxt_edge);
		if (dir<=0){
			nxt_poly_edge.u = cur_poly_edge.u;
			if (!poly.empty()){
				ll dir2 = cross_product(cur_poly_edge.make_vector(),nxt_poly_edge.make_vector());
				if (dir2>0){
					cur_poly_edge = poly.back();poly.pop_back();
				}
			}
			cur_poly_edge.v = nxt_poly_edge.v;
		}else{
			while(!poly.empty()){
				edge prev_poly_edge = poly.back();poly.pop_back();
				ll dir = cross_product(prev_poly_edge.make_vector(), cur_poly_edge.make_vector());
				if (dir==0){
					cur_poly_edge.u = prev_poly_edge.u;
					break;
				}else if (dir>0){
					poly.push_back(prev_poly_edge);
					break;
				}else{
					cur_poly_edge.u = prev_poly_edge.u;
				}
			}
			poly.push_back(cur_poly_edge);
			cur_poly_edge = edge(cur_poly_edge.v, nxt_poly_edge.u);
			while(!poly.empty()){
				edge prev_poly_edge = poly.back();poly.pop_back();
				ll dir = cross_product(prev_poly_edge.make_vector(), cur_poly_edge.make_vector());
				if (dir==0){
					cur_poly_edge.u = prev_poly_edge.u;
					break;
				}else if (dir>0){
					poly.push_back(prev_poly_edge);
					break;
				}else{
					cur_poly_edge.u = prev_poly_edge.u;
				}
			}
			poly.push_back(cur_poly_edge);
			cur_poly_edge = nxt_poly_edge;
		}
	}
	if (cur_poly_edge.v.first == poly.front().u.first && cur_poly_edge.v.second == poly.front().u.second) poly.push_back(cur_poly_edge);
	edge last_edge = poly.back();poly.pop_back();
	while(!poly.empty()){
		edge prev_edge = poly.back();
		edge nxt_edge = poly.front();
		ll dir = cross_product(prev_edge.make_vector(), last_edge.make_vector());
		if (dir<=0){
			poly.pop_back();
			last_edge.u = prev_edge.u;
			continue;
		}
		dir = cross_product(last_edge.make_vector(),nxt_edge.make_vector());
		if (dir<=0){
			poly.pop_front();
			last_edge.v = nxt_edge.v;
			continue;
		}
		break;
	}
	poly.push_back(last_edge);
	long double ans=0;
	while(!poly.empty()){
		edge cur_edge = poly.back();
		poly.pop_back();
		ans += length(cur_edge.make_vector());
		// cout<<cur_edge.u.first<< " "<<cur_edge.u.second<<" ";
		// cout<<cur_edge.v.first<< " "<<cur_edge.v.second<<endl;
	}
	cout.precision(10);
	cout<<ans<<endl;
	return 0;
}
