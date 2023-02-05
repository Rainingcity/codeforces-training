#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>
using namespace std;
typedef long long ll;
class Coord{
public:
	ll x,y;
	Coord()=default;
	Coord(ll _x, ll _y) :x(_x),y(_y){}
	bool operator< (const Coord& b) const{
		return (x==b.x?y<b.y:x<b.x);
	}
	bool operator> (const Coord& b) const{
		return (x==b.x?y>b.y:x>b.x);
	}
	bool operator== (const Coord& b) const{
		return (x==b.x && y==b.y);
	}
	bool operator!= (const Coord& b) const{
		return !this->operator==(b);
	}
	bool operator>=(const Coord& b) const{
		return !this->operator<(b);
	}
	bool operator<=(const Coord& b) const{
		return !this->operator>(b);
	}
	Coord operator+ (const Coord& b){
		return Coord(x+b.x, y+b.y);
	}
	Coord operator- (const Coord& b){
		return Coord(x-b.x, y-b.y);
	}
};
ll dotproduct(const Coord& a, const Coord& b){
	return a.x*b.x + a.y*b.y;
}
ll crossproduct(const Coord& a, const Coord& b){
	return a.x*b.y - a.y*b.x;
}
ll gcd(ll x, ll y){
	if (y==0) return x;
	return gcd(y, x%y);
}
class Vector{
public:
	ll x,y;
	Vector()=default;
	Vector(ll _x, ll _y):x(_x),y(_y){
		ll t=gcd(x,y);
		x/=t;y/=t;
	}
	Vector(Coord st, Coord ed){
		x=ed.x-st.x;
		y=ed.y-st.y;
		ll t=gcd(x, y);
		x/=t;y/=t;
	}
	bool operator==(const Vector& b) const{
		return x==b.x && y==b.y;
	}
};
namespace std{
	template<>
	struct hash<Vector>{
		size_t operator()(const Vector& v) const{
			if (v.x==0 || v.y==0) return 0;
			else return (hash<ll>()(v.x))^(hash<ll>()(v.y));
		}
	};
}
ll n;
int m;
vector<Coord> v;
unordered_map<Vector, ll> mp;
vector<bool> check;
int main(){
	cin>>n>>m;
	check.resize(n);
	for(int i=0;i<m;i++){
		ll x,y;cin>>x>>y;
		v.emplace_back(x, y);
	}
	for(int i=0;i<m;i++){
		for(int j=i+1;j<m;j++){
			ll C=crossproduct(v[i], v[j]);
			ll A=v[j].y-v[i].y;
			if (A==0) continue;
			if (C%A==0){
				ll k=C/A;
				if (1<=k && k<=n) check[k-1]=true;
			}
		}
	}
	ll ans=0;
	for(int i=0;i<n;i++){
		if (!check[i]){
			ans++;
			continue;
		}
		mp.clear();
		Coord bin(i+1, 0);
		ll mx=1;
		for(int j=0;j<m;j++){
			Vector k(bin, v[j]);
			if (mp.find(k)==mp.end()){
				// cout<<k.x<<" "<<k.y<<endl;
				mp.emplace(k, 1);
			}else{
				// cout<<k.x<<" "<<k.y<<" "<<mp[k]<<endl;
				mp.at(k)++;
				mx=max(mx, mp.at(k));
			}
		}
		ans+=mx;
	}
	cout<<ans<<endl;
	return 0;
}
