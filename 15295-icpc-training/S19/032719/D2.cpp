#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
typedef long double ld;
const ld eps = 1e-15;
int maxi(int x, int y){return x<y?y:x;}
ll maxi(ll x, ll y){return x<y?y:x;}
int n;
struct Node{
	ll x, y, val;
	Node(){}
	Node(int _x, int _y, int _v){
		x=_x;
		y=_y;
		val=_v;
	}
}v[1000100];

struct STA{
	int id;
	ll val;
	STA(){}
	STA(int i, ll S){
		id=i;
		val=S;
	}
}st[1000100];

int stn=0;

bool cmp(Node x, Node y){
	return x.x<y.x;
}

ll calcdist(int i, ll slp){
	if (st[i].id==-1) return 0;
	return st[i].val - slp*v[st[i].id].x;
}

ll check(int i, ll slp){
	return calcdist(i, slp)-calcdist(i-1, slp);
}

ll binSearch(ll slp){
	if (stn==1) return 0;
	int l=1, r=stn-1;
	while(l<r){
		int mid = (l+r+1)>>1;
		ll ord = check(mid, slp);
		if (ord==0) return calcdist(mid, slp);
		else if (ord<0) r=mid-1;
		else l=mid;
	}
	return maxi(calcdist(l,slp), calcdist(l-1,slp));
}

void update(ll &u1, ll &u2, ll &v1, ll &v2){
	if (stn==2){
		u1 = 0;
		v1 = 0;
	}else{
		u1 = v[st[stn-2].id].x;
		v1 = st[stn-2].val;
	}
	u2 = v[st[stn-1].id].x;
	v2 = st[stn-1].val;
}

int main(){
	scanf("%d", &n);
	for(int i=0;i<n;i++){
		int x,y,z;scanf("%d%d%d", &x, &y, &z);
		v[i]=Node(x,y,z);
	}
	sort(v,v+n,cmp);
	st[stn++]=STA(-1, 0);
	st[stn++]=STA(0, v[0].x*v[0].y-v[0].val);
	ll curmax = 0;
	for(int i=1;i<n;i++){
//		printf("%d ", stn);
		ll k = binSearch(v[i].y);
//		printf("%ld ", k);
		k = k + (ll)v[i].x*v[i].y - v[i].val;
		if (k > curmax){
			curmax = k;
			ll u1,u2,v1,v2;
			update(u1, u2, v1, v2);
			while(stn>1 && (ld)(curmax-v1)/(v[i].x-u1)+eps>=(ld)(v2-v1)/(u2-u1)){
				stn--;
				update(u1, u2, v1, v2);
			}
			st[stn++] = STA(i, curmax);
		}
//		printf("%ld\n", curmax);
	}
	printf("%I64d\n", curmax);
	return 0;
}
